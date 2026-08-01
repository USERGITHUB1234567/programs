#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin >> n >> m;
    string t;
    cin >> t;
    set<pair<string,long long>>s;
    for(long long i=0; i<n; i++) {
        string ss;
        cin >> ss;
        s.insert(ss,i);
    }
    /*long long k=n/m;
    vector<long long>v;
    for(long long i=0; i<n; i+=k) {
        string x="";
        for(long long j=0; j<k; j++) x+=s[i+j];
        auto it=s.lower_bound(x,0);
        if(i<n-k) cout << (*it).second << " ";
        else cout << (*it).second;
    }*/
}
