#include <iostream>

// ユークリッドの互除法
uint64_t gcd(uint64_t a, uint64_t b) {
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}

int main() {
  uint64_t a, b;
  std::cout << "Please enter two natural numbers: ";
  std::cin >> a >> b;

  std::cout << "The GCD is " << gcd(a, b) << std::endl;

  return 0;
}