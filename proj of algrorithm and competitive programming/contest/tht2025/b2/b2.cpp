#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int maxn=100005,mod=1e9+7;
int n,m,a[maxn],b[maxn],re[maxn];
void soup1()
{
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(a[j]>=b[i]) {
                re[i]+=1;
                a[j]-=1;
            }
        }
    }
    for(int i=1; i<=m; i++) cout << re[i] << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    cin >> m;
    for(int i=1; i<=m; i++) cin >> b[i];
    if(n<=5000 && m<=5000) {
        soup1();
        return 0;
    }
    sort(a+1,a+1+n);
    int da=0;
    for(int i=1; i<=m; i++) {
        re[i]=n-(lower_bound(a+1,a+1+n,b[i]+da)-a)+1;
        //if(a[lower_bound(a+1,a+1+n,b[i]+da)-a]>b[i]+da) re[i]--;
        da++;
        cout << re[i] << "\n";
    }
    //for(int i=1; i<=n; i++) cout << re[i] << "\n";
}
/*
3
3 1 1
2
1 2
*/
