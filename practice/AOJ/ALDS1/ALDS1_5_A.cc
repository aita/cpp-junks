#include <iostream>
#include <vector>

using namespace std;
using int_vec = vector<int>;

bool combination(int m, int_vec& v, int k) {
    if (m == 0)
        return true;
    if (k >= v.size())
        return false;

    return combination(m-v[k], v, k+1) || combination(m, v, k+1);
}

int main() {
    int n;
    cin >> n;

    int_vec v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int m;
        cin >> m;

        if (combination(m, v, 0)) {
            cout << "yes";
        } else {
            cout << "no";
        }
        cout << endl;
    }

    return 0;
}