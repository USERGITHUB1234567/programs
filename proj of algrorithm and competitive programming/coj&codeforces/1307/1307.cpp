#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,k,a[10004],f[10004];
int main()
{
    for(int i=1; i<10004; i++) f[i]=-1e9;
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        for(int j=i-1; j>=max(i-k,0); j--) {
            f[i]=max(f[i],f[j]);
        }
        f[i]+=a[i];
    }
    cout << *max_element(f+1,f+1+n);
}
