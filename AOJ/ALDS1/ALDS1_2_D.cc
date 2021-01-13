#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using int_vec = vector<long>;

void print(const int_vec& v) {
    int_vec::const_iterator it;
    for (it = v.begin(); it != v.end()-1; ++it) {
        cout << *it << " ";
    }
    cout << *it << endl;
}

int insertion_sort(int_vec& v, int g) {
    int count = 0;
    for (int i = g; i < v.size(); ++i) {
        auto x = v[i];
        int j = i - g;
        for (; j >= 0 && v[j] > x; j -= g) {
            v[j+g] = v[j];
            ++count;
        }
        v[j+g] = x;
    }
    return count;
}

int shell_sort(int_vec& v) {
    int_vec G;
    for (int i = 1; i <= v.size(); i = i * 3 + 1) {
        G.push_back(i);
    }
    reverse(G.begin(), G.end());
    cout << G.size() << endl;
    print(G);

    int count = 0;
    for (auto it = G.begin(); it != G.end(); ++it) {
        count += insertion_sort(v, *it);
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int_vec v;
    for (int i = 0; i < n; ++i) {
        long x;
        cin >> x;
        v.push_back(x);
    }

    auto c = shell_sort(v);
    cout << c << endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}