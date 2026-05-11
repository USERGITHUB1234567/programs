#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    freopen("dokho.inp", "r", stdin);
    freopen("dokho.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s;
    cin >> s;
    map<int,int>mp;
    string t="";
    int c=0,d=0,kq=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='a') d++;
        if(d>c) {
            d=0;
            c++;
            kq++;
        }
    }
    cout << kq;
    return 0;
}
