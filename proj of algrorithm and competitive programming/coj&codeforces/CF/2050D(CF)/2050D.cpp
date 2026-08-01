#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void solve()
{
    string s;
    cin >> s;
    string s1=s;
    for(int i=s.size()-1; i>=0; i--) {
        int t=i;
        if(i==0) continue;
        int c=s[i]-48;
        for(int j=i-1; j>=0 and c>0; j--) {
            c--;
            if(s[j]-48<c) t=j;
        }
        if(t!=i) {
            char ch=s[t];
            s[t]=c+48;
            s[i]=ch;
        }
    }
    for(int i=0; i<s.size(); i++) {
        int t=i;
        if(i==0) continue;
        int c=s1[i]-48;
        for(int j=i-1; j>=0 and c>0; j--) {
            c--;
            if(s1[j]-48<c) t=j;
        }
        if(t!=i) {
            char ch=s[t];
            s1[t]=c+48;
            s1[i]=ch;
        }
    }
    string ans=max(s,s1);
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
