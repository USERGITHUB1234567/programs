#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    map<int, int>mp;
    int x;
    while(cin >> x) {
        mp[x]++;
    }
    int d=0;
    for(auto x:mp) {
        if(x.second>=2) d++;
        if(d>=2) {
            cout << "yes";
            return 0;
        }
    }
    cout << "no";
}
