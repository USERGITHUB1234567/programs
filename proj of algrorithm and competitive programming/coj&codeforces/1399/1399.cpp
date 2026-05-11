#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int base=128,mod=1e9+7;
int h[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s;
    cin >> s;
    h[0]=0;
    s=" "+s;
    for(int i=1; i<=s.size(); i++) {
        h[i]=h[i-1]*base+s[i-1];
    }
    int k;
    cin >> k;
    while(k--) {
        int l,r;
        cin >> l >> r;

    }
}
