#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("bal.inp", "r", stdin);
    freopen("bal.out", "w", stdout);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    map<ll, ll> home_count;
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        home_count[a[i].first]++;
    }

    for (ll i = 0; i < n; i++) {
        ll home_games = n - 1;
        ll away_games = n - 1;
        if (home_count.find(a[i].second) != home_count.end()) {
            home_games += home_count[a[i].second];
            away_games -= home_count[a[i].second];
        }

        cout << home_games << " " << away_games << "\n";
    }

    return 0;
}
