#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod=998244353;
long long ft[2003][2003];
long long su(int i, int j)
{
    long long s;
    while(j>0) {
        s+=ft[i][j];
        s%=mod;
        j-=j&-j;
    }
    return s;
}
void upd(int i, int j, int v, int m)
{
    while(j<=m) {
        ft[i][j]+=v;
        ft[i][j]%=mod;
        j+=j&-j;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        memset(ft,0,sizeof(ft));
        int n,m,d;
        cin >> n >> m >> d;
        string s[n];
        for(int i=0; i<n; i++) {
            cin >> s[i];
        }
        upd(n-1,m,1,m);
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<m; j++) {
                if(s[i][j]=='X') {
                    upd(i-1,max(1,j-d+1),1,m);
                    upd(i-1,min(j+d,m),-1,m);
                }
            }
        }
        long long kq=0;
        kq+=su(0,m-1);
        cout << kq << "\n";
    }
}
