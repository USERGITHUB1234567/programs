#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define pb push_back
#define eb emplace_back
#define uni(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define mp make_pair
#define fi first
#define se second
#define file(n) freopen(n".inp", "r", stdin); freopen(n".out", "w", stdout);
using namespace std;
typedef long long ll;
const int maxn=100005;
inline int maxi(int a, int b) {return (a>b?a:b);}
inline int mini(int a, int b) {return (a<b?a:b);}
inline long long maxill(ll a, ll b) {return (a>b?a:b);}
inline long long minill(ll a, ll b) {return (a<b?a:b);}
inline long long modexp(ll b, ll e, ll m)
{
    long long res=0;
    while(e>0) {
        if(e&1) res=(res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}
int n;
pair<int,int>p[maxn];
namespace soup1
{
    bool check()
    {
        return n<=3000;
    }
    void solve()
    {
        long long kq=0;
        sort(p+1,p+1+n);
        for(int i=1; i<=n; ++i) {
            for(int j=i-1; j>=1; --j) {
                if(p[j].fi<p[i].fi && p[j].se<p[i].se) ++kq;
            }
        }
        cout << kq;
    }
}
namespace soup2
{
    struct fenwick
    {
        long long ft[maxn<<1];
        inline long long sum(int i)
        {
            long long res=0;
            while(i>0) {
                res+=ft[i];
                i-=i&-i;
            }
            return res;
        }
        inline void update(int i, long long v)
        {
            while(i<=n<<1) {
                ft[i]+=v;
                i+=i&-i;
            }
        }
    }ft;
    void solve()
    {
        sort(p+1, p+1+n);
        long long kq=0;
        for(int i=1; i<=n; ++i) {
            kq+=ft.sum(p[i].fi)-ft.sum(p[i].se);
            //cout << kq << ' ';
            ft.update(p[i].fi,1);
            ft.update(p[i].se,-1);
        }
        cout << kq;
    }
}
void implement()
{
    //if(soup1::check()) return soup1::solve();
    //soup1::solve();
    //cout << "\n";
    return soup2::solve();
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("chord")
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> p[i].fi >> p[i].se;
        if(p[i].fi>p[i].se) swap(p[i].fi, p[i].se);
    }
    implement();
}
/*
8
1 4
2 6
3 7
9 5
10 11
8 13
15 12
16 14

*/
