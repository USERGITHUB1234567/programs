#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int x,k[4];
        cin >> x;
        for(int i=1; i<=3; i++) cin >> k[i];
        bool ck=true;
        int l=2;
        while(l--) {
            if(k[x]==0) {
                ck=false;
                break;
            }
            else x=k[x];
        }
        cout << (ck?"YES\n":"NO\n");
    }

}
