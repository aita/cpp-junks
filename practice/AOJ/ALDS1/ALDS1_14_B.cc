#include <iostream>
#include <string>
#include <vector>

using namespace std;
using int_vec = vector<int>;


int_vec kmp_table(const string& p) {
    auto m = p.size();
    int_vec A(m + 1);

    A[0] = -1;
    int j = -1;
    for (int i = 0; i < m; ++i) {
        while (j >= 0 && p[i] != p[j])
            j = A[j];
        j++;
        A[i + 1] = j;
    }
    return A;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string text, p;
    cin >> text >> p;

    auto A = kmp_table(p);
    auto m = p.size();
    auto n = text.size();
    int i = 0;
    int j = 0;
    while (i < n) {
        while (j >= 0 && text[i] != p[j]) {
            j = A[j];
        }
        ++i; ++j;
        if (j == m) {
            auto k = i - m;
            cout << k << endl;
            j = A[j];
        }
    }

    return 0;
}