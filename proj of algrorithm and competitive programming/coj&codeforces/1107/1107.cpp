#include <bits/stdc++.h>
#pragma GCC ptimize("O3")
using namespace std;
vector<pair<double,string>>v;
int n;
bool cmp(pair<double,string>a, pair<double,string>b)
{
    return a.first<b.first;
}
int main()
{
    cin >> n;
    for(int i=0; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(j==i) continue;
            if(__gcd(i,j)!=1) continue;
            if(i>=j) continue;
            double d=(double)i/j;
            string s="";
            s+=to_string(i);
            s+='/';
            s+=to_string(j);
            v.push_back({d,s});
        }
    }
    v.push_back({1,"1/1"});
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<v.size(); i++) cout << v[i].second << "\n";
}
