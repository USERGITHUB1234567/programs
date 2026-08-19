#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int f[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s;
    cin >> s;
    int m;
    cin >> m;
    for(int i=1; i<s.size(); i++) {
        f[i]=f[i-1]+(s[i]==s[i-1]);
    }
    for(int i=1; i<=m; i++) {
        int l,r;
        cin >> l >> r;
        cout << f[r-1]-f[l-1] << "\n";
    }
}
