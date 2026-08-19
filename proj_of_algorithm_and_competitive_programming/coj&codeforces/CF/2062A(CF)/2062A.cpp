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
        int d=0;
        s='0'+s;
        for(int i=1; i<s.size(); i++) {
            if(s[i]=='1' and s[i-1]=='0') d++;
        }
        cout << d << "\n";
    }
}
