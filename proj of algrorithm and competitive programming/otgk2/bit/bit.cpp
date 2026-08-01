#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n,a[300005],f[300005],kq=0;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("bit.inp", "r", stdin);
    freopen("bit.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int l=1,r=1;
    bool lh=false,nh=false;
    while(r<=n) {
        if(r==1) {
            kq++;
            r++;
            continue;
        }
        if(a[r]==a[r-1]) {
            l=r;
            r++;
            kq++;
            nh=false;
            lh=false;
            continue;
        }
        if(a[r-1]<a[r]) {
            if(nh==false) {
                lh=true;
                kq+=r-l+1;
            }
            else {
                lh=false;
                nh=false;
                kq+=2;
                l=r-1;
                r++;
                continue;
            }
        }
        if(a[r-1]>a[r]) {
            nh=true;
            kq+=r-l+1;
        }
        r++;

    }
    cout << kq;
}
