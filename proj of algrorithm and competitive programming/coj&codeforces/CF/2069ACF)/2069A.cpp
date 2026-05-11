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
        bool ck=true;
        int a[n+1];
        memset(a,0,sizeof(a));
        for(int i=1; i<=n-2; i++) cin >> a[i];
        for(int i=1; i<=n-2; i++) {
            if(a[i]==0 and a[i-1]==1 and a[i+1]==1) {
                ck=false;
                break;
            }
        }
        if(ck) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
