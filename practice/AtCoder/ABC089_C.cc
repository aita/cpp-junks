#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    map<char, long long> counts;
    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        counts[s[0]] += 1;
    }

    long long ans = 0;
    string s = "MARCH";
    for (int i = 0; i < s.size()-2; ++i) {
        for (int j = i+1; j < s.size()-1; ++j) {
            for (int k = j+1; k< s.size(); ++k) {
                ans += counts[s[i]] * counts[s[j]] * counts[s[k]];
            }
        }
    }

    cout << ans << endl;

    return 0;
}
