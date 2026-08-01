#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n, p;
    string s;
    cin >> n >> p >> s;
    p--;
    int mid = n / 2;
    if (p >= mid) {
        p = n - p - 1;
    }
    int left = mid, right = -1;
    int cost = 0;
    for (int i = 0; i < mid; i++) {
        if (s[i] != s[n - i - 1]) {
            left = min(left, i);
            right = max(right, i);
            cost += min(abs(s[i] - s[n - i - 1]), 26 - abs(s[i] - s[n - i - 1]));
        }
    }
    if (right == -1) {
        cout << 0;
        return 0;
    }
    cost += min(abs(p - left) + (right - left), abs(p - right) + (right - left));
    cout << cost;

    return 0;
}
