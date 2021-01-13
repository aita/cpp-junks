#include <iostream>

using namespace std;

int fib(int n) {
    int a = 1;
    int b = 1;

    for (int i = 0; i < n-1; ++i) {
        int tmp = a;
        a = b;
        b += tmp;
    }
    return b;
}

int main() {
    int n;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}