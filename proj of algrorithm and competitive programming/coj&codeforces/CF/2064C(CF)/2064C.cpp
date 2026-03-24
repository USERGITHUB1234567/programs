#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a[n+1],f1[n+2],f2[n+2];
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) {
            if(a[i]>0) f1[i]=f1[i-1]+a[i];
            else f1[i]=f1[i-1];
        }
        for(int i=n; i>=1; i--) {
            if(a[i]<0) f2[i]=f2[i+1]-a[i];
            else f2[i]=f2[i+1];
        }
        long long kq=0;
        for(int i=1; i<=n; i++) {
            kq=max(kq,f1[i]+f2[i]);
        }
        cout << kq << "\n";
    }
}
