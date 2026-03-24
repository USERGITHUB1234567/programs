#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("str.inp", "r", stdin);
    freopen("str.out", "w", stdout);
    string s;
    cin >> s;
    int a[26];
    for(int i=0; i<s.size(); i++) {
        a[s[i]-'A']++;
    }
    cout << min({a[2],a[0],a[13]/2,a[14]});
}
