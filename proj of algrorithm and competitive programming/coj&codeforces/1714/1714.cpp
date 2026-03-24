#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int base=128,mod=1e9+423;
int h1[300005],h2[300005],p[300005];
int gethash1(int l, int r)
{
    return ((h1[r]-h1[l-1]*p[r-l+1])+mod*mod)%mod;
}
int gethash2(int l, int r)
{
    return ((h2[r]-h2[l-1]*p[r-l+1])+mod*mod)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s,t;
    cin >> s;
    p[0]=1;
    for(int i=1; i<s.size(); i++) p[i]=(p[i-1]*base)%mod;
    t=s;
    reverse(t.begin(),t.end());
    h1[0]=0;
    h2[0]=0;
    t=" "+t;
    s=" "+s;
    for(int i=1; i<s.size(); i++) {
        h1[i]=(1LL*h1[i-1]*base+s[i])%mod;
        h2[i]=(1LL*h2[i-1]*base+t[i])%mod;
    }
    int n=s.size()-1;
    for(int l=1; l<=n; l++) {
        if(gethash1(1,l)==gethash2(n-l+1,n)) {
            for(int i=n; i>l; i--) {
                cout << s[i];
            }
            cout << s.substr(1,n) << "\n";
            return 0;
        }
        else if(gethash1(n-l+1,n)==gethash2(1,l)) {
            cout << s.substr(1,n);
            for(int i=n-l; i>=1; i--) cout << s[i];
            cout << "\n";
        }
    }
}
