#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=100005;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,j,k;
        cin >> n >> j >> k;
        if(n<=k) {
            cout << "YES\n";
            continue;
        }
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        int v=a[j-1];
        sort(a,a+n);
        int i=0;
        while(i<n && a[i]<=v) i++;
        cout << (i==1?"NO":"YES") << "\n";
    }
}