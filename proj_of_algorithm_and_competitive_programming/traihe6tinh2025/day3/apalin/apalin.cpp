#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=200005,inf=1e9;
int cnt=0;
string s;
char alp[26]={'a','b','c','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void solve(char a, char b, char c, char d, int i)
{
    for(int j=0; j<26; j++) {
        if(alp[j]!=a && alp[j]!=b && alp[j]!=c && alp[j]!=d) {
            s[i]=alp[j];
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    cin >> s;
    s='*'+s;
    s+='**';
    for(int i=2; i<=n; i++) {
        if(s[i]==s[i-1]||(s[i]==s[i-2])) {
            solve(s[i-1],s[i-2],s[i+1],s[i+2],i);
            cnt++;
        }
    }
    cout << cnt << "\n";
    for(int i=1; i<=n; i++) cout << s[i];
}
