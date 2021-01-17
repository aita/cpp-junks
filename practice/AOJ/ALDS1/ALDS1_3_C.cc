#include <iostream>
#include <string>

namespace detail
{
    struct node {
        int num;
        node* prev;
        node* next;

        explicit node(int n): num(n), prev(nullptr), next(nullptr) {}
    };

    struct list {
        node* root;

        list() : root(new node(0)) {
            root->next = root;
            root->prev = root;
        }

        node* head() { return root->next; }
        node* tail() { return root->prev; }

        void insert(node* e, node* at) {
            auto n = at->next;
            at->next = e;
            e->next = n;
            e->prev = at;
            n->prev = e;
        }

        void insert(int num) {
            insert(new node(num), root);
        }

        node* find(int num) {
            auto it = root->next;
            while (it != root) {
                if (it->num == num)
                    return it;
                it = it->next;
            }
            return nullptr;
        }

        void remove(node* e) {
            e->prev->next = e->next;
            e->next->prev = e->prev;
            delete e;
        }

        void remove(int num) {
            auto at = find(num);
            if (at) remove(at);
        }
    };
}

using list = detail::list;
using node = detail::node;

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    list l;
    for (int i = 0; i < n; ++i) {
        string s;
        int x;
        cin >> s;
        if (s == "insert") {
            cin >> x;
            l.insert(x);
        } else if (s == "delete"){
            cin >> x;
            l.remove(x);
        } else if (s == "deleteFirst") {
            l.remove(l.head());
        } else if (s == "deleteLast") {
            l.remove(l.tail());
        }
    }

    auto it = l.head();
    while (it != l.tail()) {
        cout << it->num << " ";
        it = it->next;
    }
    cout << it->num << endl;

    return 0;
}