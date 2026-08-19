#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, d = 1e9;
char a[3] = {'A', 'B', 'C'};
string x, y;

bool kt(string s) {
    int len = s.size();
    for (int i = 1; i <= len / 2; i++) {
        if (s.substr(len - i, i) == s.substr(len - 2 * i, i)) {
            return false;
        }
    }
    return true;
}

int cntB(string s) {
    int t = 0;
    for (char c : s) {
        if (c == 'B') t++;
    }
    return t;
}

void dfs(int i, string s) {
    if (i >= n) {
        if (kt(s) && cntB(s) < d) {
            d = cntB(s);
            y = s;
        }
        return;
    }
    for (int j = 0; j <= 2; j++) {
        string t = s + a[j];
        if (kt(t)) {
            dfs(i + 1, t);
        }
    }
}

int main() {
    cout << "a";
    return 0;
}
