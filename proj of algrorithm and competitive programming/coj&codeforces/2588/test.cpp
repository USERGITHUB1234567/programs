#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 200005;

int n;
ll k;
ll a[MAXN];

struct Mark {
    ll m;
    int l, r;
    Mark() : m(LLONG_MIN/4), l(-1), r(-1) {}
};
Mark mk[MAXN];

// add value a[i] into multiset
inline void add_idx(int i, multiset<ll, greater<ll>>& st) {
    st.insert(a[i]);
}
// remove one occurrence of a[i] from multiset (if present)
inline void rem_idx(int i, multiset<ll, greater<ll>>& st) {
    auto it = st.find(a[i]);
    if (it != st.end()) st.erase(it);
}
// compute sum of elements after the first k largest (i.e., sum of elements ranked k+1, k+2, ...)
inline ll sum_after_k(const multiset<ll, greater<ll>>& st) {
    if (k <= 0) return 0;
    ll cnt = 0;
    ll ans = 0;
    for (auto x : st) {
        ++cnt;
        if (cnt > k) ans += x;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> k)) return 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // Build mk[] for segments of consecutive non-negative numbers scanning from right to left
    // mk[i] will describe a segment that *starts* at i (left index) and ends at mk[i].r (right index)
    // and mk[i].m stores -sum_of_smallest_k_in_that_segment (as in your original code).
    // Initialize mk entries via constructor above.

    vector<ll> segVals;
    int segR = -1; // right endpoint of current segment (when scanning right-to-left)
    for (int i = n; i >= 1; --i) {
        if (a[i] >= 0) {
            if (segR == -1) segR = i;
            segVals.push_back(a[i]);
        } else {
            // ended a non-negative segment at segR (if any)
            if (segR != -1) {
                sort(segVals.begin(), segVals.end()); // ascending
                if ((ll)segVals.size() >= k) {
                    ll s = 0;
                    for (int t = 0; t < (int)k; ++t) s += segVals[t];
                    mk[i+1].m = -s;        // segment started at i+1
                    mk[i+1].l = i+1;
                    mk[i+1].r = segR;
                } else {
                    mk[i+1].m = LLONG_MIN/4;
                    mk[i+1].l = i+1;
                    mk[i+1].r = segR;
                }
                segVals.clear();
                segR = -1;
            }
        }
    }
    // if we ended with a non-negative segment that reaches index 1
    if (segR != -1) {
        sort(segVals.begin(), segVals.end());
        if ((ll)segVals.size() >= k) {
            ll s = 0;
            for (int t = 0; t < (int)k; ++t) s += segVals[t];
            mk[1].m = -s;
            mk[1].l = 1;
            mk[1].r = segR;
        } else {
            mk[1].m = LLONG_MIN/4;
            mk[1].l = 1;
            mk[1].r = segR;
        }
        segVals.clear();
    }

    // Example debug print of mk[] (only for positions that were set)
    // Comment out in final submission if not needed.
    /*
    for (int i = 1; i <= n; ++i) {
        if (mk[i].l != -1) {
            cerr << "mk[" << i << "]: m=" << mk[i].m << " l=" << mk[i].l << " r=" << mk[i].r << "\n";
        }
    }
    */

    // Sliding window / two-pointer logic using multiset
    multiset<ll, greater<ll>> cur;
    // initialize window with first k elements (1-based). If k > n, we insert all available.
    int r = 0, l = 1;
    for (int i = 1; i <= n && i <= (int)k; ++i) add_idx(i, cur), r = i;

    ll ans = sum_after_k(cur);
    // iterate expanding r until n
    while (r < n) {
        // try to move r forward by one
        ++r;
        add_idx(r, cur);

        // optional: if you want a fixed-size window of size k, remove from left
        // but original code's intended windowing is unclear; here we keep all inserted elements
        // and compute sum_after_k(cur) each time.
        ll now = sum_after_k(cur);
        ans = max(ans, now);

        // If you intended to slide the left pointer under some condition, implement here.
        // Example (if window size must be <= some limit): while (r - l + 1 > window_size) rem_idx(l++ , cur);
    }

    cout << ans << '\n';
    return 0;
}
