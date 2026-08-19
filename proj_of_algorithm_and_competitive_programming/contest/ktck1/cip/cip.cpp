#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    freopen("cip.inp", "r", stdin);
    freopen("cip.out", "w", stdout);
    int n;
    cin >> n;
    string t;
    cin >> t;
    string s="";
    s+=t[0];
    bool ck=false;
    for(int i=1; i<t.size(); i++) {
        if(t[i]==s[s.size()-1]) ck=true;
        if(t[i]==s[s.size()-1] and i<n-1) {
            s+=t[i+1];
            i++;
        }
    }
    if(ck) cout << s;
    else cout << t;
    return 0;
}
