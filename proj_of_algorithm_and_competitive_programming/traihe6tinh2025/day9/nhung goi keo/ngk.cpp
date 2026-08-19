#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=1000006;
int a[maxn],p[maxn],n,m,kq=INT_MAX;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) p[i]=p[i-1]+a[i];
	for(int l=1; l<=n-m+1; l++) {
		int r=l+m-1,mid1=l+(m-1)/2,mid2=l+m/2;
		for(int mid:{mid1,mid2}) {
			int x=a[mid];
			int lc=lower_bound(a+l,a+r+1,x)-(a+l),sl=p[l+lc-1]-p[l-1];
			int d=x*lc-sl;
			int up=upper_bound(a+l,a+r+1,x)-a;
			int hc=r-up+1,sh=p[r]-p[up-1],sp=sh-x*hc;
			int move=max(d,sp);
			kq=min(kq,move);
		}
	}
	cout << kq;
}