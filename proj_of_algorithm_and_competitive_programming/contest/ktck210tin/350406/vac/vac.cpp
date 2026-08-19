#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,d,kq=0,m=0;
string s[102];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("vac.inp", "r", stdin);
    freopen("vac.out", "w", stdout);
    cin >> n >> d;
    for(int i=1; i<=n; i++) cin >> s[i];
    for(int r=0; r<d; r++) {
        bool ck=true;
        for(int j=1; j<=n; j++) {
            if(s[j][r]=='x') {
                ck=false;
                break;
            }
        }
        if(ck) m++;
        else {
            kq=max(kq,m);
            m=0;
        }
    }
    kq=max(kq,m);
    cout << kq;
}
