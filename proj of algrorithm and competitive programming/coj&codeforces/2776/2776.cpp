#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, m, ma=0;
        cin >> n >> m;
        pair<long long, long long> p[n];
        long long b[n];
        for (int i=0; i<n; i++) {
            cin >> p[i].first >> p[i].second;
            ma=max(ma, p[i].second);
            b[i]=p[i].first;
        }
        sort(p, p+n);
        sort(b, b+n);
        long long a[m];
        for (int i=0; i<m; i++) {
            cin >> a[i];
            if (a[i]>=ma) {
                cout << -1 << "\n";
                continue;
            }
            long long vt=lower_bound(b,b+n, a[i])-b;
            if(vt==0) {
                cout << p[vt].first-a[i] << "\n";
                continue;
            }
            if (p[vt-1].second>a[i]) {
                cout << 0 << "\n";
            } else {
                cout << p[vt].first-a[i] << "\n";
            }
        }
    }
    return 0;
}
