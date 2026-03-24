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
const int maxn=100005,mod=1000000007,sq=sqrt(maxn);
int n;
pair<ll,ll>mandalay[maxn];
ll f[maxn], sum[sq+10][maxn];
struct event
{
    int type,d,j;
};
//vector<event>ev;
pair<ll,ll>ev[maxn];
struct segtree
{
    long long st[4*maxn],laz[4*maxn];
    void build(int id, int l, int r)
    {
        if(l==r) {
            st[id]=f[l];
            return;
        }
        int m=(l+r)>>1;
        build(id<<1,l,m);
        build(id<<1|1,m+1,r);
        st[id]=st[id<<1]+st[id<<1|1];
    }
    void push(int id, int l, int r)
    {
        if(!laz[id]) return;
        st[id]+=(r-l+1)*laz[id];
        st[id]%=mod;
        laz[id<<1]+=laz[id];
        laz[id<<1|1]+=laz[id];
        laz[id<<1]%=mod;
        laz[id<<1|1]%=mod;
        laz[id]=0;
    }
    void upd(int id, int l, int r, int i, int j, long long v)
    {
        push(id,l,r);
        if(l>j || r<i) return;
        if(l>=i && r<=j) {
            st[id]+=v*(r-l+1);
            st[id]%=mod;
            laz[id<<1]+=v;
            laz[id<<1|1]+=v;
            laz[id<<1]%=mod;
            laz[id<<1|1]%=mod;
            push(id,l,r);
            return;
        }
        int m=(l+r)>>1;
        upd(id<<1,l,m,i,j,v);
        upd(id<<1|1,m+1,r,i,j,v);
        st[id]=(st[id<<1]%mod+st[id<<1|1]%mod)%mod;
    }
    long long query(int id, int l, int r, int i, int j)
    {
        push(id,l,r);
        if(l>j || r<i) return 0;
        if(l>=i && r<=j) return st[id]%mod;
        int m=(l+r)>>1;
        return (query(id<<1,l,m,i,j)%mod+query(id<<1|1,m+1,r,i,j)%mod)%mod;
    }
}seg;
void soup1()
{
    f[1]=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=mandalay[i].se; j++) {
            int t=i+j*mandalay[i].fi;
            if(t>n) break;
            f[t]+=f[i];
            f[t]%=mod;
        }
    }
    //cout << f[n];
    long long kq=0;
    for(int i=1; i<=n; i++) kq+=f[i],kq%=mod;
    cout << kq;
}
void soup2()
{
    for(int i=1; i<=n; i++) {
        seg.upd(1,1,n,i,min((ll)n,i+mandalay[i].se),1LL);
    }
    cout << seg.query(1,1,n,1,n)%mod;
}
bool cmp(event a, event b)
{
    return a.j<b.j;
}
void soup3()
{
    f[1]=1;
    int s=sqrt(n);
    /*for(int i=1; i<=n; i++) {
        if(mandalay[i].fi<=s) {
            if(i+d<=n) ev[i+d]={d,1}//ev.pb({1,d,i+d});
            if(i+(1+d*mandalay[i].se)<=n) ev[i+d*(1+mandalay[i].se)]={d,0}//ev.pb({0,d,i+d*(mandalay[i].se+1)});
        }
    }*/
    //sort(all(ev),cmp);
    /*for(auto[t,d,j]:ev) {
        if(t==1) sum[d][j%d]+=f[j];
        else sum
    }*/
    for(int i=1; i<=n; i++) ev[i]={-1,-1};
    for(ll i=1; i<=n; i++) {
        ll d=mandalay[i].fi;
        //if(d==0) continue;
        if(mandalay[i].fi>s && d!=0) {
            int j=i+mandalay[i].fi;
            for(j;j<=n; j+=mandalay[i].fi) {
                if(j>n) break;
                f[j]+=f[i];
                f[j]%=mod;
            }
        }
        else if(mandalay[i].fi<=s && d!=0) {
            if(i+d<=n && d!=0) ev[i+d]={d,1};//ev.pb({1,d,i+d});
            if(i+(1+d*mandalay[i].se)<=n && d!=0) ev[i+d*(1+mandalay[i].se)]={d,0};//ev.pb({0,d,i+d*(mandalay[i].se+1)});
        }
        if(ev[i].se==0 && d!=0) sum[d][i%d]-=f[i];
        else if(ev[i].fi==1 && d!=0) sum[d][i%d]+=f[i];
        //cout << d << " " << i << "\n";
        //cout << d << " " << i%d << "\n";
        //cout << sum[d][i%d] << " ";
        if(d!=0)f[i]+=sum[d][i%d];
        //cout << 1 << " ";
        f[i]%=mod;
    }
    ll kq=0;
    for(int i=1; i<=n; i++) kq+=f[i];
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("cuuho")
    cin >> n;
    bool kts2=true;
    for(int i=1; i<=n; i++) {
        cin >> mandalay[i].fi >> mandalay[i].se;
        if(mandalay[i].fi!=1) kts2=false;
    }
    if(kts2) {
        soup2();
        return 0;
    }
    soup3();
}
