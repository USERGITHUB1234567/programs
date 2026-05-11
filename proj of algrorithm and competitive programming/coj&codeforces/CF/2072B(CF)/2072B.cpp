#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        long long dt=0,dd=0;
        for(int i=0; i<n; i++) {
            if(s[i]=='_') dd++;
            else dt++;
        }
        if(dd<1 or dt<2) {
            cout << 0 << "\n";
            continue;
        }
        cout << (dt/2)*(dt-dt/2)*dd << "\n";
    }
}
