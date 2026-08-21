#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int>mp;
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int d=0,t=0;
    string c="";
    for(auto x:mp) {
        if(x.second>d) {
            d=x.second;
            c=x.first;
        }
    }
    for(auto x:mp) {
        if(x.first!=c) t+=x.second;
    }
    if(t<d) cout << c;
    else cout << "NONE";
}
