#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int kq=0;
string s,a;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> s >> a;
	int n=s.size();
	for(int i=0; i<n; i++) {
		int j=i;
		for(int k=0; k<n; k++) {
			if(j<n && a[k]==s[j]) j++;
		}
		kq=max(kq,j-i);
	}
	cout << n-kq;
}