#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=500005;
struct point {
	int x,y,c;
}p[maxn];
int st[8*maxn],laz[8*maxn],cand[2*maxn],base[2*maxn],stid[8*maxn];
void build(int id, int l, int r) {
	if(l==r) {
		st[id]=base[l];
		stid[id]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	if(st[id]>=st[id<<1|1]) {
		st[id]=st[id<<1|1]
		stid[id]=stid[id<<1];
	}
	else {
		st[id]=st[id<<1|1];
		stid[id]=stid[id<<1|1];
	}
}
void down(int id) {
	st[id<<1]+=laz[id];
	laz[id<<1]+=laz[id];
	st[id<<1|1]+=laz[id];
	laz[id<<1|1]+=laz[id];
	laz[id]=0;
}
void upd(int id, int l, int r, int u, int v, int val) {
	if(v<l || r<u) return;
	if(u<=l && r<=v) {
		st[id]+=val;
		laz[id]+=val;
		return;
	}
	down(id);
	int mid=(l+r)>>1;
	upd(id<<1,l,mid,u,v,val);
	upd(id<<1|1,mid+1,r,u,v,val);
	if(st[id<<1]>=st[id<<1|1]) {
		st[id]=st[id<<1];
		stid[id]=stid[id<<1];
	}
	else {
		st[id]=st[id<<1|1];
		stid[id]=stid[id<<1|1];
	}
}
pair<int,int>query
int n;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> p[i].x >> p[i].y >> p[i].c;
	}
}
/*
6
0 0 2
2 0 -5
1 1 3
2 3 4
2 4 -4
3 1 -1

5
4 4 0
4 4 -3
1 3 -1
4 2 3
1 1 -2
*/