#include <iostream>
#include <vector>
#include <algorithm>

using int64 = long long;

using namespace std;
using int_vec = vector<int64>;

void heapify(int_vec& v, int i) {
    int max;

    auto h = v.size();
    auto l = i * 2 + 1;
    auto r = i * 2 + 2;
    if (l < h && v[l] > v[i]) {
        max = l;
    } else {
        max = i;
    }
    if (r < h && v[r] > v[max]) {
        max = r;
    }

    if (max != i) {
        swap(v[i], v[max]);
        heapify(v, max);
    }
}

int parent(int i) {
    return (i - 1) / 2;
}

void insert(int_vec& v, int64 x) {
    v.push_back(x);

    int i = v.size() - 1;
    while (i > 0 && v[parent(i)] < v[i]) {
        swap(v[parent(i)], v[i]);
        i = parent(i);
    }
}

int main() {
    int_vec v;

    while (1) {
        string s;
        cin >> s;
        if (s == "end")
            break;

        if (s == "insert") {
            int x;
            cin >> x;
            insert(v, x);
        } else if (s == "extract") {
            cout << v[0] << endl;
            swap(v[0], v.back());
            v.pop_back();
            heapify(v, 0);
        }
    }

    return 0;
}