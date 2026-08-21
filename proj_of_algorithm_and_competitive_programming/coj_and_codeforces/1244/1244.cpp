#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long w,h,n;
    cin >> w >> h >> n;
    pair<char,long long>p[n];
    set<long long>sth,stv;
    multiset<long long>sh,sv;
    sth.insert(0);sth.insert(h);
    stv.insert(0);stv.insert(w);
    sh.insert(h);
    sv.insert(w);
    for(long long i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
        if(p[i].first=='H') {
            sth.insert(p[i].second);
            auto cur=sth.lower_bound(p[i].second),pre=cur,nxt=cur;
            pre--;
            nxt++;
            sh.erase(sh.lower_bound(*nxt-*pre));
            sh.insert(*cur-*pre);
            sh.insert(*nxt-*cur);
        }
        if(p[i].first=='V') {
            stv.insert(p[i].second);
            auto cur=stv.lower_bound(p[i].second),pre=cur,nxt=cur;
            pre--;
            nxt++;
            sv.erase(sv.lower_bound(*nxt-*pre));
            sv.insert(*cur-*pre);
            sv.insert(*nxt-*cur);
        }
        cout << (*--sh.end())*(*--sv.end()) << "\n";
    }
}
