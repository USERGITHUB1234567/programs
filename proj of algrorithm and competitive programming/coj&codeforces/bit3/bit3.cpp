#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bit3.inp", "r", stdin);
    freopen("bit3.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long cnt = count(s.begin(), s.end(), '1');
    long long t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        if (s[x-1] == '0') {
            s[x-1] = '1';
            cnt++;
        } else {
            s[x-1] = '0';
            cnt--;
        }
        cout << cnt << "\n";
    }
}
