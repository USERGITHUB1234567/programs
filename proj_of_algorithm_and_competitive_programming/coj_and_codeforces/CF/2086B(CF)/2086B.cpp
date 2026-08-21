#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        ll x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<ll> prefix(n+1, 0);
        for (int i = 1; i <= n; i++){
            prefix[i] = prefix[i-1] + a[i-1];
        }
        ll S = prefix[n];
        vector<ll> f(n, 0);
        for (int pos = 0; pos < n; pos++){
            ll initial = prefix[n] - prefix[pos];
            if(initial >= x){
                int lo = pos + 1, hi = n;
                while(lo < hi){
                    int mid = lo + (hi - lo) / 2;
                    if(prefix[mid] - prefix[pos] >= x)
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                f[pos] = lo - pos;
            } else {
                ll rem = x - initial;
                ll m = (rem - 1) / S;
                ll sumAfter = initial + m * S;
                ll needed = x - sumAfter;
                int lo = 1, hi = n;
                while(lo < hi){
                    int mid = lo + (hi - lo) / 2;
                    if(prefix[mid] >= needed)
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                f[pos] = (n - pos) + m * n + lo;
            }
        }
        ll total = 0;
        ll totalElements = (ll)k * n;
        for (int pos = 0; pos < n; pos++){
            ll rem = totalElements - pos - f[pos];
            if(rem < 0) continue;
            ll maxC = rem / n;
            ll cnt = maxC + 1;
            if(cnt > k) cnt = k;
            total += cnt;
        }

        cout << total << "\n";
    }
    return 0;
}
