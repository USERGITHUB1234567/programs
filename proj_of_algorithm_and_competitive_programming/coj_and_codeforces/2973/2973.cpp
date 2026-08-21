#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int k,m;
string s;
vector<string>v;
bool dx(string s)
{
    string t=s;
    reverse(t.begin(),t.end());
    if(t==s) return true;
    return false;
}
int main()
{
    int kq=0;
    cin >> k >> m >> s;
    //v.push_back(s);
    for(int i=1; i<=k-1; i++) {
        int l,r;
        cin >> l >> r;
        v.push_back(s.substr(l-1,r-l+1));
    }
    for(int i=0; i<=s.size()-m; i++) {
        //string t=s.substr(i,m);
        string t;
        for(auto sex:v) t+=sex;
        t+=s.substr(i,m);
        if(dx(t)) kq++;
    }
    cout << kq;
}
