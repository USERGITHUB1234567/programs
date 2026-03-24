#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
//#define fi first
//#define se second
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
typedef long long ll;
const int maxn=100005;
int n;
long long a[maxn],pre[maxn];
struct node
{
    ll t1,t2,li,ri;
};
struct segtree
{
    node st[maxn<<2];
    //ll le[maxn<<2],ri[maxn<<2];
    node merg(node a, node b)
    {
        return {a.t1^b.t1,max({a.t1,b.t1,a.t2,b.t2,a.li,a.ri,b.li,b.ri}),a.t1,b.t1};
        //return {st[id<<1].fi^st[id<<1|1].fi,max({st[id<<1].fi,st[id<<1|1].se,st[(id<<1)<<1|1].fi,st[(id<<1)<<1|1].se,st[(id<<1|1)<<1].fi,st[(id<<1|1)<<1].se})};
    }
    void build(int id, int l, int r)
    {
        if(l==r) {
            st[id].t1=a[l];
            st[id].t2=a[l];
            st[id].li=0;
            st[id].ri=0;
            return;
        }
        int m=(l+r)>>1;
        build(id<<1,l,m);
        build(id<<1|1,m+1,r);
        st[id].li=st[id<<1].t1;
        st[id].ri=st[id<<1|1].t1;
        st[id]=merg(st[id<<1],st[id<<1|1]);
    }
    void upd(int id, int l, int r, int i, int v)
    {
        if(l==r) {
            st[id].t1=v;
            st[id].t2=v;
            return;
        }
        int m=(l+r)>>1;
        if(i<=m) upd(id<<1,l,m,i,v);
        else upd(id<<1|1,m+1,r,i,v);
        st[id].li=st[id<<1].t1;
        st[id].ri=st[id<<1|1].t1;
        st[id]=merg(st[id<<1],st[id<<1|1]);
    }
    node query(int id, int l, int r, int i, int j)
    {
        if(l>j || r<i) return {0,0};
        if(l>=i && r<=j) return st[id];
        int m=(l+r)>>1;
        return merg(query(id<<1,l,m,i,j),query(id<<1|1,m+1,r,i,j));
    }
}seg;
string conv(int x)
{
    string s="";
    while(x>0) {
        if(x&1) s='1'+s;
        else s='0'+s;
        x>>=1;
    }
    while(s.size()<32) s='0'+s;
    return s;
}
int conv2(string s)
{
    int res=0;
    //cout << s;
    for(char c:s) {
        if(c=='1') res=1+(res*2);
        else res*=2;
    }
    return res;
}
struct trie
{
    int tr[maxn<<5][2]={0};
    int cur=0;
    trie()
    {
        for(int i=0; i<maxn; i++) tr[i][0]=tr[i][1]=0;
    }
    void add(int x)
    {
        string s=conv(x);
        int pos=0;
        for(char c:s) {
            int j=c-'0';
            if(!tr[pos][j]) tr[pos][j]=++cur;
            pos=tr[pos][j];
        }
    }
    int query(int x)
    {
        string s=conv(x);
        string res="";
        //cout << s;
        int pos=0;
        for(char c:s) {
            int j=c-'0',t=1-j;
            //if(!tr[pos][1] && !tr[pos][0]) break;
            //d++;
            //cout << tr[pos][j] << " ";
            if(tr[pos][t]) {
                pos=tr[pos][t];
                res+='1';
            }
            else {
                pos=tr[pos][j];
                res+='0';
            }
        }
        return conv2(res);
        //return 0;
    }
}t;
void soup1()
{
    long long res=0;
    pair<int,int>ans;
    for(int i=1; i<=n; i++) {
        long long x=a[i];
        if(x>res) ans={i,i};
        res=max(res,x);
        for(int j=i+1; j<=n; j++) {
            x^=a[j];
            //res=max(res,x);
            if(x>res) {
                res=x;
                ans={i,j};
            }
        }
    }
    cout << res /*<< " " << ans.fi << " " << ans.se*/;
}
void soup2lo()
{
    seg.build(1,1,n);
    cout << seg.query(1,1,n,1,n).t2;
}
void soup2()
{
    for(int i=1; i<=n; i++) pre[i]=pre[i-1]^a[i];
    int ans=0;
    t.add(0);
    for(int i=1; i<=n; i++) {
        ans=max(ans,t.query(pre[i]));
        t.add(pre[i]);
    }
    //t.add(4);
    //cout << t.query(5);
    cout << ans;
    //cout << conv(4);
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("sumxor")
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    /*if(n<=1000) {
        soup1();
        return 0;
    }*/
    soup2();
}
