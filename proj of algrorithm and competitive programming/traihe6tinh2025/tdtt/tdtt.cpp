#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=11,maxx=102,mod=1000000007;
int n,fm,f[1<<maxn],t;
vector<int>a[maxx];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            for(int j=0; j<x; j++) {
                int u;
                cin >> u;
                a[u].push_back(i);
            }
        }
        fm=1<<n;
        f[0]=1;
        for(int i=1; i<=100; i++) {
            for(int mask=0; mask<fm; mask++) {
                if(f[mask]=0) continue;
                for(int x:a[i]) {
                    if(!(mask&(1<<x))) {
                        f[mask|(1<<x)]+=f[mask];
                        f[mask|(1<<x)]%=mod;
                    }
                }
            }
        }
        cout << f[fm-1]<< "\n";
    }
}
