#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int>a,b;
        for(int i=0; i<n; i++) {
            if(s[i]=='A') a.push_back(i+1);
            else b.push_back(i+1);
        }

    }
}
