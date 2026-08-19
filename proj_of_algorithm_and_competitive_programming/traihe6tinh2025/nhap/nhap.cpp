#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;

const int MAXN = 100000 + 5;

int n;
ll d[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    // sort descending, 1-based
    sort(d + 1, d + n + 1, greater<ll>());

    ll best = LLONG_MAX;
    const int Kmax = 30;  // beyond ~30 doublings is always suboptimal

    // try each block size k = 1..Kmax
    for(int k = 1; k <= Kmax; k++){
        ll t = 0;
        for(int i = 1; i <= n; i++){
            // if this is the first task of a new block (except i=1), take break
            if(i > 1 && (i - 1) % k == 0){
                t += 3600;
                if(t >= best) break;
            }
            int j = (i - 1) % k;        // position in current block: 0..k-1
            t += d[i] * (1LL << j);     // cost = d[i] * 2^j
            if(t >= best) break;
        }
        best = min(best, t);
    }

    cout << best << "\n";
    return 0;
}
