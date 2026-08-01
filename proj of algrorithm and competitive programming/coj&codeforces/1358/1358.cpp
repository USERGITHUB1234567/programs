#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, k;
    cin >> m >> k;
    string s;
    cin >> s;
    deque<int> v;
    for (int i = m - 1; i >= 0; i--) {
        v.push_back(i);
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            int x = v.back();
            v.pop_back();
            v.push_front(x);
        } else if (s[i] == 'B') {
            int x = v[v.size() - 2];
            v.erase(v.end() - 2);
            v.push_front(x);
        }
    }

        cout << v[k] << " " << v[k - 1] << " " << v[k - 2];

    return 0;
}
