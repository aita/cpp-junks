#include <iostream>

int main() {
  unsigned long limit;
  std::cout << "upper limit: ";
  std::cin >> limit;

  unsigned long sum = 0;
  for (unsigned long i = 3; i <= limit; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      ++sum;
    }
  }
  std::cout << "sum = " << sum << std::endl;

  return 0;
}
