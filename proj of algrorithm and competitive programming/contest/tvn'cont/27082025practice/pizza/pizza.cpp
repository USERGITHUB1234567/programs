#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int maxn=200005;
const ll inf=LLONG_MAX;
int n,m;
ll s2[maxn];
struct pizza_restaurant
{
    ll s,p,id;
}p[maxn];
pair<int,int>query[maxn];
vector<int>dislike[maxn];
bool cmps2(pizza_restaurant a, pizza_restaurant b)
{
    return a.s<b.s;
}
void soup1()
{
    //sort(p+1,p+1+n,cmps1);
    for(int q=1; q<=m; q++) {
        map<ll,bool>mp;
        auto[c,k]=query[q];
        for(int i:dislike[q]) mp[i]=true;
        long long res=inf;
        for(int i=1; i<=n; ++i) {
            if(mp[i]) continue;
            res=min(res,(c-p[i].s)*(c-p[i].s)+p[i].p);
        }
        cout << res << "\n";
    }
}
void soup2()
{
    for(int i=1; i<=n; i++) s2[i]=p[i].s;
    sort(s2+1,s2+1+n);
    for(int q=1; q<=m; q++) {
        auto[c,k]=query[q];
        int p1=lower_bound(s2+1,s2+1+n,c)-s2,p2=p1-1;
        int d1=(s2[p1]-c)*(s2[p1]-c),d2=(s2[p2]-c)*(s2[p2]-c);
        if((p2==0 || d1<d2) && p1!=n+1) cout << d1+p[p1].p << "\n";
        else cout << d2+p[p2].p << "\n";

    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("pizza")
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> p[i].s >> p[i].p;
        p[i].id=i;
    }
    int kts2=true;
    for(int i=1; i<=m; i++) {
        cin >> query[i].fi >> query[i].se;
        if(query[i].se) kts2=false;
        if(i>1 && query[i].fi!=query[i-1].fi) kts2=false;
        for(int j=1; j<=query[i].se; j++) {
            int x;
            cin >> x;
            dislike[i].pb(x);
        }

    }
    if(kts2) {
        soup2();
        return 0;
    }
    soup1();
}
