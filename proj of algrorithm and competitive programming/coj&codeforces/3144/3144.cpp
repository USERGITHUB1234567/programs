#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
typedef long long ll;
const int maxn=300005,mod=998244353;
int n,m,num[maxn],low[maxn],f1[maxn],f2[maxn],comp[maxn],timer=0,nscc=0;
vector<int>adj[maxn],b[maxn];
stack<int>st;
void dfs(int u) {
	num[u]=low[u]=++timer;
	st.push(u);
	for(int v:adj[u]) {
		if(comp[v]) continue;
		if(!num[v]) {
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else low[u]=min(low[u],num[v]);
	}
	if(low[u]==num[u]) {
		nscc++;
		while(1) {
			int v=st.top();st.pop();
			comp[v]=nscc;
			if(v==u) break;
		}
	}
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1,u,v; i<=m; ++i) {
   		cin >> u >> v;
   		adj[u].pb(v);
   		b[v].pb(u);
    }
    for(int i=1; i<=n; ++i) {
    	if(!num[i]) dfs(i);
    }
    vector<int>scc[nscc+1];
    for(int i=1; i<=n; ++i) scc[comp[i]].pb(i);
    reverse(scc+1,scc+1+nscc);
	for(int i=1; i<=nscc; ++i) {
		int sum=0;
		for(int u:scc[i]) {
			f1[u]=1;
			for(int v:b[u]) {
				if(comp[u]!=comp[v]) {
					f1[u]=(f1[u]+f2[v])%mod;
				}
			}
			sum=(sum+f1[u])%mod;
		}
		int k=scc[i].size()-2,s=1,cur=1;
		for(int j=1; j<=k; ++j) {
			cur=1LL*cur*(k-j+1)%mod;
			s=(s+cur)%mod;
		}
		for(int u:scc[i]) f2[u]=(f1[u]+1LL*s*(sum-f1[u]+mod))%mod;
	}
	int kq=0;
	for(int i=1; i<=n; ++i) kq=(kq+f2[i])%mod;
	cout << kq;
	
}