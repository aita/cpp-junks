#include <iostream>

struct Iterator {
  long long n;
  long long a, b;

  long long operator*() const {
    return a;
  }

  bool operator != (const Iterator& rhs) const {
    return n != rhs.n;
  }

  void operator ++() {
    long long tmp = b;
    b = a+b;
    a = tmp;
    ++n;
  }
};

struct Fibonacci {
  long long n;

  auto begin() {
    return Iterator{1, 1, 1};
  }

  auto end() {
    return Iterator{n+1, -1, -1};
  }
};

int main() {
  for (auto n: Fibonacci{10}) {
    std::cout << n << std::endl;
  }

  return 0;
}
