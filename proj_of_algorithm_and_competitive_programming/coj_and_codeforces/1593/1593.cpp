#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool ck=false;
    for(int i=0; i<s.size(); i++) {
        int n=s[i]-48;
        if(n<=6) {
            ck=true;
            s[i]=char(s[i]+3);
        }
        if(n<=3) {
            ck=true;
            s[i]=char(s[i]+3);
        }
        if(n<=0) {
            ck=true;
            s[i]=char(s[i]+3);
        }
        if(ck) break;
    }
    if(ck) {
        cout << s;
        return 0;
    }
    for(int i=s.size()-1; i>=0; i--) {
        int n=s[i]-48;
        if(n>=3) {
            s[i]=char(s[i]-3);
            break;
        }
    }
    cout << s;
}
