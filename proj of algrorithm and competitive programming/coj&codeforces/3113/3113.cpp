#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int maxn=100005;
int n,a[maxn],dc=0,dl=0,kq=0,f[maxn],cl=-1,cc=-1;
signed main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) f[i]=f[i-1]+a[i];
    for(int i=1; i<=n; i++) {
        if(f[i]%2==0) {
            kq+=dc;
            dc++;
            if(i-cc<=1 && dc>0) {
                kq--;
                //cout << i << " ";
            }
            cc=i;
            if(i!=1) kq++;
        }
        else {
            kq+=dl;
            dl++;
            if(i-cl<=1 && dl>0) {
                kq--;
                //cout << i << " ";
            }
            cl=i;
        }
        //cout << kq << ' ';
    }
    cout << kq;
}
