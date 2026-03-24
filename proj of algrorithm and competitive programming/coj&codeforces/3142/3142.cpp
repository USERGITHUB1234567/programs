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
const int maxn=300005;
int n,m,q,num[maxn],low[maxn],timer=0,comp[maxn],c[maxn],ncomp=0;
long long s[maxn],p[maxn];
bool inst[maxn];
vector<int>adj[maxn];
stack<int>st;
void dfs(int u, int ) {
    num[u]=low[u]=++timer;
    inst[u]=true;
    st.push(u);
    for(int v:adj[u]) {
        //if(v==pa) continue;
        if(!num[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        } 
        else if(inst[v]) low[u]=min(low[u],num[v]);
    }
    if(low[u]==num[u]) {
        int cur;
        long long sum=0;
        ++ncomp;
        while(true) {
            cur=st.top();st.pop();
            inst[cur]=false;
            ++sum;
            if(cur==u) break;
        }
        c[ncomp]=sum;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        //adj[v].pb(u);
    }
    //dfs(1,0);
    for(int i=1; i<=n; ++i) {
        if(!num[i]) dfs(i,0);
    }
    sort(c+1,c+ncomp+1,greater<int>());
    for(int i=1; i<=ncomp; ++i) {
        s[i]=s[i-1]+c[i];
        p[i]=p[i-1]+c[i]*s[i-1];
    }
    cin >> q;
    while(q--) {
        long long k;
        cin >> k;
        int l=1, r=ncomp, t=0;
        while (l<=r) {
            int mid=(l+r)>>1;
            if (p[mid]<=k) {
                t=mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        ll ans=s[t];
        ll rem=k-p[t];
        if(t<ncomp && s[t]>0) {
            ll can=rem/s[t];
            if(can>c[t+1]) can=c[t+1];
            ans+=can;
        }
        cout << ans << "\n";
    }
}