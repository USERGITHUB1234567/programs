#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=5003;
long long n,a[maxn];
map<int,bool>mp;
vector<long long >ans;
bool mk[maxn];
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	/*for(int i=2; i<=n; i++) {
		int t1=a[i];
		for(int j=i-1; j>=1; j--) {
			int h=t1-a[j],t2=a[j]+h;
			if(binary_search(a+1+i,a+1+n,t2)==1) mp[h]=true;
		}
	}*/
	if(n==1) {
		cout << 1;
		return 0;
	}
	/*for(int i=2; i<=n; i++) {
		if(ans.empty()) {
			ans.push_back(a[i]-a[1]);
			continue;
		}
		bool ck=false;
		for(int x:ans) {
			int t1=a[i]-x;
			if(binary_search(a+1,a+1+i,t1)==1) {
				ck=true;
				break;
			}
		}
		if(!ck) ans.push_back(a[i]-a[1]);
	}
	cout << ans.size();*/
	int kq=0;
	for(int i=2; i<=n; i++) {
		if(mk[i]) continue;
		int t1=a[i]-a[1];
		kq++;
		int pos=i;
		for(int j=i+1; j<=n; j++) {
			int t2=a[pos]+t1;
			if(a[j]==t2) {
				mk[j]=true;
				//t1=a[j]-a[i];
				pos=j;
			}
		}
	}
	cout << kq;
	//cout << mp.size();
}