#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int p[maxn],n,m;
pair<int,int>prob[maxn];
bool cmp(pair<int,int>a, pair<int,int>b) {
	return (long double)(a.second/a.first)<(long double)(b.second/b.first);
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> prob[i].first;
	sort(prob+1,prob+1+n,cmp);
	for(int i=1; i<=m; i++) {
		int x,y;
		cin >> x >> t;
		
	}
}