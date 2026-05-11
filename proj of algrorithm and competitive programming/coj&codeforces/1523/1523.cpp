#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long base=128;
const long long mod=1e9+7;
int main()
{
    string s,w;
    cin >> s >> w;
    int n=s.size(),m=w.size();
    if(n<m) {
        cout << 0;
        return 0;
    }
    long long p=1;
    for(int i=1; i<m; i++) p=(p*base)%mod;
    long long h1=0,h2=0,re=0;
    for(int i=0; i<m; i++) {
        h1=(h1*base+s[i])%mod;
        h2=(h2*base+w[i])%mod;
    }
    if(h1==h2) re++;
    for(int i=m; i<n; i++) {
        h1=((h1-s[i-m]*p)%mod+mod)%mod;
        h1=(h1*base+s[i])%mod;
        if(h1==h2) re++;
    }
    cout << re;
}
