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
        if(s.size()==2) {
            cout << s[1]-48 << "\n";
            continue;
        }
        else {
            int m=1e9;
            for(int i=0; i<s.size(); i++) m=min(m,s[i]-48);
            cout << m << "\n";
        }
    }
}
