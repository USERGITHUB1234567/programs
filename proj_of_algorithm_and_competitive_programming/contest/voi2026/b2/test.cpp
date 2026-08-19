#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
using namespace std;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 36;
const ll INF = 1e18 + 36;
const long double EPS = 1e-15;
const int N = 1e5 + 3667;
int minmize(int a, int b) {
    return a < b ? a : b;
}
int maxmize(int a, int b) {
    return a > b ? a : b;
}
ll Minmize(ll a, ll b) {
    return a < b ? a : b;
}
ll Maxmize(ll a, ll b) {
    return a > b ? a : b;
}
int n, q, w[N], s[N], MX;
ll S;
vector<pair<ll, ll>>gift;
namespace soup1 {
    bool check(ll &M, ll &K, ll &T) {
        if (T==0)
            return true;
        ll need = T * K;
        ll take = 0;
        ll W = 0;
        for (int i = 0;i < n && take < need; ++i) {
            ll cap = Minmize(gift[i].second,T);
            ll cur = Minmize(cap,need-take);
            take += cur;
            W += cur * gift[i].first;
            if (W > M)
                return false;
        }
        if (take < need)
            return false;
        return W <= M;
    }
    void solve() {
        for (int Q = 1; Q <= q; ++Q) {
            int type;
            cin >> type;
            if (type == 1) {
                ll M, K, T;
                cin >> M >> K >> T;
                cout << check(M, K, T) << '\n';
            }
            else {
                ll M, K;
                cin >> M >> K;
                ll low = 0, high = S / K, best = 0;
                while(low <= high) {
                    ll mid = (low + high) >> 1;
                    if (check(M, K, mid)) {
                        best = mid;
                        low = mid + 1;
                    }
                    else
                        high = mid - 1;
                }
                cout << best << '\n';
            }
        }
    }
}
namespace Finale_Delicious_Hot_Cooked_Soup_By_Truong_Dz_Cute_Top1_The_Gioi_Ahihihihihihihihihihi {
    struct FenwickTree {
        int n;
        vector<ll> b;
        FenwickTree(int _n) {
            n = _n;
            b.assign(n + 1, 0);
        }
        void init(int _n) {
            n = _n;
            b.assign(n + 1, 0);
        }
        void update(int i, ll v) {
            for(; i <= n; i += i & -i)
                b[i] += v;
        }
        ll query(int i) {
            ll s = 0;
            if (i <= 0)
                return s;
            for(; i; i -= i & -i)
                s += b[i];
            return s;
        }
        void range(int l, int r, ll v) {
            update(l, v);
            if(r + 1 <= n)
                update(r + 1 ,-v);
        }
        ll sum(int l, int r) {
            if (l > r)
                return 0;
            return query(r) - query(l - 1);
        }
    };
    struct Query {
        int t;
        ll M, K, T;
        int id;
    };
    void solve() {
        vector<ll> ans(q, 0);
        sort(all(gift), [&] (pair<ll, ll> A, pair<ll, ll>B) {
             return A.second < B.second;
        });
        vector<Query> Q1, Q2, Q;
        for (int tr = 0; tr < q; ++tr) {
            int t;
            cin >> t;
            if (t == 1) {
                ll M, K, T;
                cin >> M >> K >> T;
                Q1.push_back({t, M, K, T, tr});
                Q.push_back({t, M, K, T, tr});
            }
            else {
                ll M, K;
                cin >> M >> K;
                Q2.push_back({t, M, K, 0, tr});
                Q.push_back({t, M, K, 0, tr});
            }
        }
        ///Q1
        FenwickTree Cnt1(MX), Sum1(MX), Cnt2(MX), Sum2(MX);
        ll BIT1Copy = 0;
        ll BIT2Sum = n;
        auto update = [&] (pair<ll, ll>G) {
            Cnt2.update(G.first, -1);
            Sum2.update(G.first, -G.first);
            Cnt1.update(G.first, G.second);
            Sum1.update(G.first, G.first * G.second);
            BIT1Copy += G.second;
            --BIT2Sum;
        };
        ll PW = 1;
        while ((PW << 1LL) <= MX)
            PW <<= 1LL;
        auto check = [&] (ll  &M, ll &K, ll &T) -> bool {
            ll need = T * K;
            ll avail = BIT1Copy +  T * BIT2Sum;
            if (need > avail)
                return false;
            int pos = 0;
            ll take_cnt = 0, take_sum = 0;
            for (int step = PW; step; step >>= 1) {
                 int nxt = pos + step;
                 if (nxt <= MX) {
                    ll block_cnt = Cnt1.b[nxt] + T * Cnt2.b[nxt];
                    if (take_cnt + block_cnt < need) {
                        take_cnt += block_cnt;
                        take_sum += Sum1.b[nxt] + T * Sum2.b[nxt];
                        pos = nxt;
                    }
                 }
            }
            take_sum += (need - take_cnt) * (pos + 1);
            return take_sum <= M;
        };
        auto Query1 = [&]() {
            for (int i = 0; i < n; ++i) {
                Cnt2.update(gift[i].first, 1);
                Sum2.update(gift[i].first, gift[i].first);
            }
            vector<pair<ll, int>> order;
            for (auto [t, M, K, T, id] : Q1)
                order.push_back({T, id});
            sort(all(order));
            int ptr = 0;
            for (auto [T, id] : order) {
                while (ptr < n && gift[ptr].second <= T) {
                    update(gift[ptr]);
                    ++ptr;
                }
                ans[id] = check(Q[id].M, Q[id].K, T);
            }
        };
        Query1();
        ///Q2
        auto Query2 = [&]() {
            vector<ll>low(q, 0), high(q, 0);
            for (auto [t, M, K, T, id] : Q2)
                high[id] = S / K + 1;
            while (true) {
                vector<pair<ll, int>> mid;
                bool change = false;
                for (auto [t, M, K, T, id] : Q2)
                    if (low[id] + 1 < high[id]) {
                        mid.push_back({(low[id] + high[id]) >> 1LL, id});
                        change = true;
                    }
                if (!change)
                    break;
                Cnt1.init(MX);
                Sum1.init(MX);
                Cnt2.init(MX);
                Sum2.init(MX);
                for (int i = 0; i < n; ++i) {
                    Cnt2.update(gift[i].first, 1);
                    Sum2.update(gift[i].first, gift[i].first);
                }
                BIT1Copy = 0;
                BIT2Sum = n;
                int ptr = 0;
                sort(all(mid));
                for (int l = 0; l < (int) mid.size();) {
                    ll T = mid[l].first;
                    while (ptr < n && gift[ptr].second <= T) {
                        update(gift[ptr]);
                        ++ptr;
                    }
                    int r = l;
                    while (r < (int) mid.size() && mid[r].first == T)
                        ++r;
                    for (int i = l; i < r; ++i) {
                        int id = mid[i].second;
                        if (check(Q[id].M, Q[id].K, T))
                            low[id] = T;
                        else
                            high[id] = T;
                    }
                    l = r;
                }
            }
            for (auto [t, M, K, T, id] : Q2)
                ans[id] = low[id];
        };
        Query2();
        for (int i = 0; i < q; ++i)
            cout << ans[i] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //file("GIFT");
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        MX = maxmize(MX, w[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        S += s[i];
    }
    for (int i = 0; i < n; ++i)
        gift.push_back({w[i], s[i]});
    sort(all(gift));
    Finale_Delicious_Hot_Cooked_Soup_By_Truong_Dz_Cute_Top1_The_Gioi_Ahihihihihihihihihihi :: solve();
    return 0;
}