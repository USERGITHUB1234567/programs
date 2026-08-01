#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,v=0;
        cin >> n;
        int a[n+1];
        for(int i=1; i<=n; i++) cin >> a[i];
        bool ck=false;
        for(int i=1; i<=n; i++) {
            if(a[i]!=0) {
                ck=true;
                break;
            }
        }
        if(!ck) {
            cout << 3 << "\n" << 1 << " " << 2 << "\n" << 2 << " " << n-1 << "\n" << 1 << " " << 2 << "\n";
            continue;
        }
        int i=1;
        while(a[i]==0) i++;
        vector<pair<int,int>>an;
        if(i!=1)an.push_back({1,i});
        bool kt=false;
        for(int j=i; j<=n; j++) {
            if(a[j]==0) {
                kt=true;
                break;
            }
        }
        if(!kt) {
            int t;
            if(i==1) t=n;
            else {
                t=n-i+2;
            }
            an.push_back({1,t});
        }
        cout << an.size() << "\n";
        for(auto [u,v]:an) cout << u << " " << v << "\n";
    }
}
