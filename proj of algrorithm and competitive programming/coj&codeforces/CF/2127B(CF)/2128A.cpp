#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=31;
long long n,c,a[maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> c;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1,a+1+n,greater<long long>());
        long long mul=1,kq=0;
        for(int i=1; i<=n; i++) {
            int w=a[i]*mul;
            if(w>mul) kq++;
            mul*=2;
        }
        cout << kq << "\n";
    }
}