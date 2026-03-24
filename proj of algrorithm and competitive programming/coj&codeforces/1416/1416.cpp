#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool ck=false;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='A') {
            if(s[i+1]=='B') ck=true;
            if((s[i+2]=='A' or s[i+2]=='B') and (s[i+3]!='A' and s[i+3]!='B'))
        }
        if(s[i]=='B') {
            if(s[i+1]=='A') ck=true;
            if((s[i+2]=='A' or s[i+2]=='B') and (s[i+3]!='A' and s[i+3]!='B'))
        }
    }
    if(ck) cout << "YES";
    else cout << "NO";
}
