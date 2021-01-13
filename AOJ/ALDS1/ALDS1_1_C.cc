#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const size_t N = 100000000 + 1;
bitset<N> sieve;

void eratosthenes() {
    for (int i = 2; i < N; ++i) {
        sieve[i] = true;
    }

    for (int i = 2; i < sqrt(N); ++i) {
        if (sieve[i]) {
            for (int j = 2; i * j < N; ++j) {
                sieve[i*j] = false;
            }
        }
    }
}

bool is_prime(int n) {
    return sieve[n];
}

int main() {
    eratosthenes();

    int n;
    cin >> n;

    int count;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (is_prime(x)) {
            // cerr << "debug: " <<  x << endl;
            count++;
        }
    }
    cout << count << endl;

    return 0;
}