#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        string s;
        cin >> n >> k >> s;
        if(n==1) {
            cout << "no\n";
            continue;
        }
        bool ck=false;
        for(int i=1; i<n; i++) {
            if(s[i]!=s[i-1]) {
                ck=true;
                break;
            }
        }
        string t=s;
        reverse(t.begin(),t.end());
        if(s<t) {
            cout << "yes\n";
            continue;
        }
        if(!ck) {
            cout << "no\n";
            continue;
        }
        if(k>=1) cout << "yes\n";
        else cout << "no\n";
    }
}
