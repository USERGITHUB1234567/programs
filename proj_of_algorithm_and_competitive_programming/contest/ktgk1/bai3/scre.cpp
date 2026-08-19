#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("scre.inp", "r", stdin);
    freopen("scre.out", "w", stdout);
    string s,t;
    cin >> s >> t;
    int d=0;
    if(s.size()<t.size()) swap(s,t);
    for(int i=s.size()-1; i>=0; i--) {
        if(s==t) {
            d+=s.size()+1;
            break;
        }
        if(i+1>t.size()) {
            d++;
            s.erase(i,1);
        }
        else {
            d+=2;
            s.erase(i,1);
            t.erase(i,1);
        }
    }
    cout << d;
}
