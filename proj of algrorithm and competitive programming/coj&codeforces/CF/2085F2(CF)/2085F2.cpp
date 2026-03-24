#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,k,kq=0;
        cin >> n >> k;
        int a[n+1];
        map<int,int>mp;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) {
            if(i>k) break;
            if(mp[a[i]]==0) {
                mp[a[i]]++;
                continue;
            }
            else {
                for(int j=i+1; j<=n; j++) {
                    if(mp[a[j]]==0) {
                        kq+=j-i;
                        swap(a[i],a[j]);
                        break;
                    }
                }
            }
        }
        cout << kq << "\n";
    }
}
