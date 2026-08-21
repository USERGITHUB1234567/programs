#include <bits/stdc++.h>
#pragma GCC optimize("O3")
typedef long long ll;
using namespace std;

int main() {
    ll n, a, b, kq = 0;
    cin >> n >> a >> b;
    pair<ll, ll> p[100001];
    if(b-n>a) a=b-n;
    priority_queue<ll> pq;
    for (ll i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);

    ll in = 1;
    for (ll i = a; i < b; i++) {
        while (in <= n && p[in].first <= i) {
            pq.push(p[in].second);
            in++;
        }
        if (!pq.empty()) {
            kq += pq.top();
            pq.pop();
        }
    }
    cout << kq << endl;
    return 0;
}
