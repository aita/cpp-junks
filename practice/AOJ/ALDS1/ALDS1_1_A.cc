#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int> &A)
{
    auto it = A.begin();
    for (; it != A.end() - 1; ++it)
    {
        cout << *it << " ";
    }
    cout << *it << endl;
}

void insertion_sort(vector<int> &A)
{
    for (int i = 1; i < A.size(); ++i)
    {
        int key = A[i];
        int j = i - 1;
        for (; j >= 0 && A[j] > key; --j)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = key;
        print_vector(A);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    print_vector(A);
    insertion_sort(A);

    return 0;
}