#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=102,inf=INT_MAX;
int n,a[maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int>v;bool ck=true;
        for(int i=1,x; i<=n; ++i) {cin >> x;if(x!=-1) v.push_back(x);if(x==0) ck=false;}
        sort(all(v));
        v.erase(unique(all(v)),v.end());
        if(v.size()<=1 && ck) cout << "yes\n";
        else cout << "no\n";
    }
}