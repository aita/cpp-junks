#include <iostream>
#include <vector>

using namespace std;
using int_vec = vector<int>;

void print(const int_vec& v) {
    int_vec::const_iterator it;
    for (it = v.begin(); it != v.end()-1; ++it) {
        cout << *it << " ";
    }
    cout << *it << endl;
}

void insertion_sort(int_vec& v) {
    for (int i = 1; i < v.size(); ++i) {
        int x = v[i];
        int j;
        for (j = i; j >= 0; --j) {
            if (x >= v[j-1])
                break;
            v[j] = v[j-1];
        }
        v[j] = x;
        print(v);
    }
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

    print(v);
    insertion_sort(v);

    return 0;
}