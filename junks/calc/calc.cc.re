#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>

/*!max:re2c*/

enum TokenKind {
  kEOF,
  kInt,
  kAdd,
  kSub,
  kMul,
  kDiv,
  kNewline,
  kError,
};

class Scanner {
 public:
  Scanner(std::ifstream&& fs, std::size_t buffer_size = 1024)
      : fs_(std::move(fs)),
        eof_(false),
        buffer_size_(buffer_size),
        buffer_(new unsigned char[buffer_size]),
        cursor_(&buffer_[0] + buffer_size),
        marker_(&buffer_[0] + buffer_size),
        token_(&buffer_[0] + buffer_size),
        limit_(&buffer_[0] + buffer_size) {
    fill(1);
  }

  int fill(int need) {
    if (eof_) {
      return 1;
    }

    auto free = token_ - &buffer_[0];
    if (free < need) {
      buffer_size_ = (buffer_size_ + need) * 2;
      auto new_buffer = std::make_unique<unsigned char[]>(buffer_size_);
      std::memcpy(&new_buffer[0], token_, limit_ - token_);
      buffer_ = std::move(new_buffer);
    } else {
      std::memmove(&buffer_[0], token_, limit_ - token_);
    }
    cursor_ = &buffer_[0] + (cursor_ - token_);
    marker_ = &buffer_[0] + (marker_ - token_);
    limit_ = &buffer_[0] + (limit_ - token_);
    token_ = &buffer_[0];

    fs_.read((char*)limit_, buffer_size_ - (limit_ - token_));
    limit_ += fs_.gcount();
    if (fs_.eof()) {
      eof_ = true;
      std::memset(limit_, 0, YYMAXFILL);
      limit_ += YYMAXFILL;
    }
    return 0;
  }

  std::size_t length() { return cursor_ - token_; }

  std::string text() { return std::string(token_, token_ + length()); }

  int scan() {
  loop:
    token_ = cursor_;

    /*!re2c
    re2c:api:style = free-form;
    re2c:define:YYCTYPE  = "unsigned char";
    re2c:define:YYCURSOR = cursor_;
    re2c:define:YYMARKER = marker_;
    re2c:define:YYLIMIT  = limit_;
    re2c:define:YYFILL   = "if (fill(@@) != 0) return -1;";
    re2c:indent:top = 2;
    re2c:indent:string = "  ";
    "0" | ([1-9][0-9]*) {
      return kInt;
    }
    "+" {
      return kAdd;
    }
    "-" {
      return kSub;
    }
    "*" {
      return kMul;
    }
    "/" {
      return kDiv;
    }
    "\n" {
      return kNewline;
    }
    * { return kError; }
    [\x00] { return kEOF; }
    [ \r\t\f] {
        goto loop;
    }
    */
  }

 private:
  std::ifstream fs_;
  bool eof_;
  std::size_t buffer_size_;
  std::unique_ptr<unsigned char[]> buffer_;
  unsigned char* cursor_;
  unsigned char* marker_;
  unsigned char* token_;
  unsigned char* limit_;
};

class ParseError : public std::runtime_error {
 public:
  explicit ParseError(const std::string& what_arg)
      : std::runtime_error(what_arg) {}
};

class Parser {
 public:
  Parser(Scanner&& scanner) : scanner_(std::move(scanner)), tok_(-1) {}

  int peek() {
    if (tok_ == -1) {
      tok_ = scanner_.scan();
    }
    return tok_;
  }

  void consume() { tok_ = -1; }

  int factor() {
    auto tok = peek();
    if (tok == kInt) {
      consume();
      return std::atoi(scanner_.text().c_str());
    }
    throw ParseError("unexpected token");
  }

  int term() {
    auto x = factor();
    auto tok = peek();
    while (tok == kMul || tok == kDiv) {
      consume();
      auto y = factor();
      if (tok == kMul)
        x *= y;
      if (tok == kDiv)
        x /= y;
      tok = peek();
    }
    return x;
  }

  int expr() {
    auto x = term();
    auto tok = peek();
    while (tok == kAdd || tok == kSub) {
      consume();
      auto y = term();
      if (tok == kAdd)
        x += y;
      if (tok == kSub)
        x -= y;
      tok = peek();
    }
    return x;
  }

  bool parse() {
    auto tok = peek();
    while (tok == kNewline) {
      consume();
      tok = peek();
    }
    if (tok == kEOF) {
      return false;
    }
    auto x = expr();
    std::cout << x << std::endl;
    return true;
  }

 private:
  Scanner scanner_;
  int tok_;
};

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "usage: " << argv[0] << " FILE" << std::endl;
    std::exit(1);
  }
  std::string filename(argv[1]);
  std::ifstream ifs(filename, std::ios::in | std::ios::binary);
  if (!ifs) {
    std::cerr << "failed to open" << filename << std::endl;
    std::exit(1);
  }
  Scanner scanner(std::move(ifs));
  Parser parser(std::move(scanner));
  while (parser.parse()) {}
  return 0;
}
