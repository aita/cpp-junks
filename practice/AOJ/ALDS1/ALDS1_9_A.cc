#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (auto i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (auto j = 0; j < v.size(); ++j) {
        auto k = j + 1;
        cout << "node " << k << ": ";
        cout << "key = " << v[j] << ", ";

        if (j > 0) {
            cout << "parent key = " << v[(j-1)/2] << ", ";
        }
        if (j*2+1 < v.size()) {
            cout << "left key = " << v[j*2+1] << ", ";
        }
        if (j*2+2 < v.size()) {
            cout << "right key = " << v[j*2+2] << ", ";
        }
        cout << endl;
    }

    return 0;
}