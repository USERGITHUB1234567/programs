#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,d=0;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
            if(a[i]==0) d++;
        }
        bool ck=true;
        for(int i=1; i<n; i++) {
            if(a[i]==0 && a[i-1]==0) {
                ck=false;
                break;
            }
        }
        if(!ck || !d) cout << "YES\n";
        else cout << "NO\n";
    }
}
