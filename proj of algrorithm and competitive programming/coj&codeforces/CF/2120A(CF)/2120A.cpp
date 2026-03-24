#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int l1,b1,l2,b2,l3,b3;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
		if(l1==l2 && l2==l3) {
			if(b1+b2+b2==l1) cout << "YES\n";
			else cout << "NO\n";
		}
		else if(b1==b2 && b2==b3) {
			if(l1+l2+l3==b1) cout << "YES\n";
			else cout << "NO\n";
		}
		else if()
		else cout << "NO\n";
	}
}