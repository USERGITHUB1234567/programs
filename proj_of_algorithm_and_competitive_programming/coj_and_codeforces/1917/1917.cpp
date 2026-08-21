#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long m,n;
    cin >> m >> n;
    long long kq=n;
    pair<long long,long long>p[n];
    string s;
    for(long long i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
        //s+='0';
    }
    for(long long i=0; i<m; i++) s+='0';
    for(long long i=0; i<n; i++) {
        s[p[i].first]=1;
        s[p[i].second]=1;
        int q = (p[i].second-p[i].first)+1;
        int vt = p[i].first-1;
        string t=s.substr(vt, q);
        sort(t.begin(),t.end());
        if(t[t.size()-1]=='1') kq-=2;
    }
    cout << kq;
}
