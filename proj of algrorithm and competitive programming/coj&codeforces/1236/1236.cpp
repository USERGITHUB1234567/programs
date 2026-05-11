#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,x,y;
    cin >> n >> x >> y;
    pair<long long,long long>p[n];
    set<double>st;
    int dt=0,dn=0,d=0;
    for(long long i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
        if(p[i].first==x) {
            dt=1;
            continue;
        }
        if(p[i].second==y) {
            dn=1;
            continue;
        }
        else st.insert(double((p[i].second)-y)/((p[i].first)-x));
    }
    cout << st.size()+dt+dn;
}
