#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        map<char,int>mp;
        for(char c:s) {
            mp[c]++;
        }
        bool ck=false;
        for(int i=1; i<s.size()-1; i++) {
            if(mp[s[i]]>1) {
                ck=true;
                break;
            }
            //cout << mp[s[i]] << " ";
        }
        cout << (ck ? "YES" : "NO") << "\n";
        //cout << "\n";
    }
    return 0;
}