#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    string t="abcdefghijklmnopqrstuvwxyz";
    map<char,int>mp;
    for(int i=0; i<26; i++) mp[t[i]]=i+1;
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.size()>n) {
        cout << "Impossible";
        return 0;
    }
    int k=0;
    for(int i=0; i<s.size(); i++) {
        k+=mp[s[i]];
    }
    cout << k;
    return 0;
}
