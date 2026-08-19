#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        int kq=0;
        map<int,int>mp;
        for(int i=1; i<=n*m; i++) {
            int x;
            cin >> x;
            kq=max(kq,x);
            mp[x]++;
        }
        cout << (mp[kq]>1?kq:kq-1) << "\n";
    }
}