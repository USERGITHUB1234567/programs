#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define ford(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
int n;
ll x,s[200005],f[200005];
ll dp[200005];
const ll inf=1e18;
void sub12(){
    f[0]=x;
    ford(i,1,n)
        dp[i]=inf;
    ford(i,1,n)
        ford(j,0,i-1)
            dp[i]=min(s[i]*f[j]+dp[j],dp[i]);
    cout << dp[n];

}
struct line{
    ll m,c;
    ll cal(ll x){
        return m*x+c;
    }
};
struct Node{
    line li;
    int l,r;
};
Node seg[3000006];
int cnt;
void update(int& node,ll l,ll r,line x){
    if(!node){
        node=++cnt;
        seg[node]={x,0,0};
        return;
    }
    ll mid=(r+l)/2;
    bool bmid=(x.cal(mid)<seg[node].li.cal(mid));
    bool bl=(x.cal(l)<seg[node].li.cal(l));
    bool br=(x.cal(r)<seg[node].li.cal(r));
    if(bl&&br){
        seg[node].li=x;
        return;
    }
    else if(!bl&&!br) return;
    if(bmid) swap(seg[node].li,x);
    if(bmid!=bl) update(seg[node].l,l,mid,x);
    else update(seg[node].r,mid+1,r,x);
}
ll query(int node,ll l,ll r,ll x){
    if(!node) return inf;
    ll ans=seg[node].li.cal(x);
    if(l==r) return ans;
    ll mid=(l+r)/2;
    if(x<=mid) return min(ans,query(seg[node].l,l,mid,x));
    else return min(ans,query(seg[node].r,mid+1,r,x));
}
void sub3(){
    int root=0;
    update(root,0,2e12,{x,0});
    ford(i,1,n){
        dp[i]=query(root,0,2e12,s[i]);
        update(root,0,2e12,{f[i],dp[i]});
    }
    cout << dp[n];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("game.inp","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> x;
    ford(i,1,n) cin >> s[i];
    ford(i,1,n) cin  >> f[i];
    if(n<=2000) sub12();
    else sub3();
}
