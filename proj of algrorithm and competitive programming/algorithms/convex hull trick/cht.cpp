#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=100005;
struct cht {
    pair<int,int>lines[maxn];
    vector<pair<int,int>>hull;
    bool cmp(const pair<int,int>& l1,const pair<int,int>& l2) {return (l1.fi<l2.fi) || (l1.fi==l2.fi && l1.se<l2.se);}
    bool bad(const pair<int,int>& l1,const pair<int,int>& l2,const pair<int,int>& l3) {return (l3.se-l1.se)*(l2.fi-l1.fi)>=(l2.se-l1.se)*(l3.fi-l1.fi);}
    void add(pair<int,int>&l) {
        if(hull.size() && hull.back().fi==l.fi && hull.back().se<=l.se) return;
        if(hull.size() && hull.back().fi==l.fi && hull.back().se>l.se) hull.pop_back();
        while(hull.size()>=2 && bad(hull[hull.size()-2],hull[hull.size()-1],l))
            hull.pop_back();
        hull.pb(l);
    }
    long long query(long long x) {
        int l=0,r=hull.size()-1;
        while(l<r) {
            int m=(l+r)/2;
            if(hull[m].fi*x+hull[m].se<hull[m+1].fi*x+hull[m+1].se)
                r=m;
            else
                l=m+1;
        }
        return hull[l].fi*x+hull[l].se;
    }
};
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
}