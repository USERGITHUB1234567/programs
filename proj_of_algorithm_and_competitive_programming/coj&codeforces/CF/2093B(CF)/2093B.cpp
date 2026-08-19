#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int re=0;
        bool i0=false;
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i]=='0') {
                if(!i0) {
                    re++;
                }
            }
            else {
                i0=true;
                re++;
            }
        }
        cout << re-1 << "\n";
    }
}
