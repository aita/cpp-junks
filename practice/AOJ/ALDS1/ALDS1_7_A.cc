#include <iostream>
#include <vector>

using namespace std;

struct node {
    int parent;
    int depth;
    vector<int> children;

    node() : parent(-1), children() {}
};

int main() {
    int N;
    cin >> N;
    vector<node> node_list(N, node());
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < b; ++j) {
            int x;
            cin >> x;
            node_list[a].children.push_back(x);
            node_list[x].parent = a;
        }
    }

    for (int i = 0; i < N; ++i) {
        int depth = 0;
        auto it = &node_list[i];
        while (it->parent != -1) {
            it = &node_list[it->parent];
            ++depth;
        }
        node_list[i].depth = depth;
    }

    for (int i = 0; i < N; ++i) {
        auto& node = node_list[i];
        cout << "node " << i;
        cout << ": parent = " << node.parent;
        cout << ", depth = " << node.depth << ", ";
        if (node.parent == -1) {
            cout << "root";
        } else if (node.children.size() > 0) {
            cout << "internal node";
        } else {
            cout << "leaf";
        }
        cout << ", [";
        auto& children = node.children;
        if (children.size() > 0) {
            auto it = children.begin();
            for (; it != children.end()-1; ++it) {
                cout << *it << ", ";
            }
            cout << *it;
        }
        cout << "]" << endl;
    }

    return 0;
}

