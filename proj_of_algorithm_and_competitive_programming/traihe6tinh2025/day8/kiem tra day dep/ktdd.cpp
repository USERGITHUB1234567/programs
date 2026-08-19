#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,c;
        cin >> n >> c;
        vector<int>a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        vector<int>f(c+1,0);
        for(int x:a) f[x]=1;
        vector<int>pr(c+1,0);
        for(int i=1; i<=c; i++) {
            pr[i]=pr[i-1]+f[i];
        }
        bool ck=true;
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        for(int y:a) {
            if(!ck) break;
            int m=c/y;
            for(int k=1; k<=m; k++) {
                if(f[k]) continue;
                int l=k*y,r=min(l+y-1,c);
                if(pr[r]-pr[l-1]>0) {
                    ck=false;
                    break;
                }
            }
        }
        cout << (ck?"Yes":"No") << "\n";
    }
}
