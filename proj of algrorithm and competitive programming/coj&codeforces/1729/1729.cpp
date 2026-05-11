#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m;
string s[51];
map<string,int>mp;
int c1=0,c2=0;
pair<string,int>p[51];
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i].first;
    cin >> m;
    int ma=0;
    string kq="";
    for(int i=1; i<=m; i++) {
        int t1,t2;
        char c;
        cin >> t1 >> c >> t2;
        string t;
        cin >> t;
        int b=abs(c1-t1)+abs(c2-t2);
        c1=t1;
        c2=t2;
        mp[t]+=b;
    }
    for(int i=1; i<=n; i++) {
        p[i].second=mp[p[i].first];
        if(p[i].second>ma) {
            ma=p[i].second;
            kq=p[i].first;
        }
    }
    cout << kq << " " << ma;
}
