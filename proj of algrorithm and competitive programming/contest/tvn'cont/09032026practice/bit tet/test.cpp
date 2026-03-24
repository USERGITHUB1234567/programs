#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int q;
    if (!(cin >> n >> q))
        return 0;

    ll sumD = 0;      // sum of x for D ops => row[n]
    ll cntD_full = 0; // count of D with x == n => row[1] contribution
    unordered_map<ll, ll> cntL, cntR;
    cntL.reserve(q * 2);
    cntR.reserve(q * 2);

    vector<pair<char, long long>> ops;
    ops.reserve(q);
    for (int i = 0; i < q; ++i)
    {
        char s;
        long long x;
        cin >> s >> x;
        ops.emplace_back(s, x);
        if (s == 'D')
        {
            sumD += x;
            if (x == n)
                ++cntD_full;
        }
        else if (s == 'L')
        {
            ++cntL[x];
        }
        else if (s == 'R')
        {
            ++cntR[x];
        }
    }

    // Row part
    ll row_max = sumD;
    ll row_min = cntD_full; // as argued, only D with x == n add to row 1 (value 1 each)
    ll row_diff = row_max - row_min;

    // Build sorted lists for L and R distinct x
    vector<long long> xsL, xsR;
    xsL.reserve(cntL.size());
    xsR.reserve(cntR.size());
    for (auto &p : cntL)
        xsL.push_back(p.first);
    for (auto &p : cntR)
        xsR.push_back(p.first);
    sort(xsL.begin(), xsL.end());
    sort(xsR.begin(), xsR.end());

    // Build suffix sums for L: suf_cntL[i], suf_sumxL[i] over xsL[i..end]
    int mL = xsL.size(), mR = xsR.size();
    vector<ll> suf_cntL(mL + 1, 0), suf_sumxL(mL + 1, 0);
    vector<ll> suf_cntR(mR + 1, 0), suf_sumxR(mR + 1, 0);
    for (int i = mL - 1; i >= 0; --i)
    {
        ll x = xsL[i];
        ll c = cntL[x];
        suf_cntL[i] = suf_cntL[i + 1] + c;
        suf_sumxL[i] = suf_sumxL[i + 1] + c * x;
    }
    for (int i = mR - 1; i >= 0; --i)
    {
        ll x = xsR[i];
        ll c = cntR[x];
        suf_cntR[i] = suf_cntR[i + 1] + c;
        suf_sumxR[i] = suf_sumxR[i + 1] + c * x;
    }

    auto contribL_at = [&](long long j) -> ll
    {
        // sum over L ops of max(0, x - (j-1)) = sum_{x >= j} (x - (j-1)) * cnt
        if (mL == 0)
            return 0;
        // find first index idx with xsL[idx] >= j
        int idx = int(lower_bound(xsL.begin(), xsL.end(), j) - xsL.begin());
        if (idx >= mL)
            return 0;
        ll ssum = suf_sumxL[idx];
        ll scnt = suf_cntL[idx];
        return ssum - (j - 1) * scnt;
    };
    auto contribR_at = [&](long long j) -> ll
    {
        // sum over R ops of max(0, x - (n - j)) = sum_{x >= n-j+1} (x - (n - j)) * cnt
        if (mR == 0)
            return 0;
        long long t = n - j + 1; // threshold: x >= t
        if (t <= 1)
        {
            // all x >= 1 included
            ll ssum = suf_sumxR[0];
            ll scnt = suf_cntR[0];
            return ssum - (n - j) * scnt;
        }
        int idx = int(lower_bound(xsR.begin(), xsR.end(), t) - xsR.begin());
        if (idx >= mR)
            return 0;
        ll ssum = suf_sumxR[idx];
        ll scnt = suf_cntR[idx];
        return ssum - (n - j) * scnt;
    };

    // Candidate j positions where 'col' can change slope: 1, n,
    // x, x+1 for each L (we include x and x+1), and n-x, n-x+1 for each R.
    // Clamp to [1..n]. Also include neighbors j-1,j+1 for safety.
    unordered_set<long long> cand_set;
    cand_set.reserve((xsL.size() + xsR.size()) * 4 + 10);
    auto add_pos = [&](long long j)
    {
        if (j < 1 || j > n)
            return;
        cand_set.insert(j);
    };
    add_pos(1);
    add_pos(n);
    for (auto x : xsL)
    {
        add_pos(x);
        add_pos(x + 1);
        add_pos(x - 1);
        add_pos(x + 2);
    }
    for (auto x : xsR)
    {
        add_pos(n - x);
        add_pos(n - x + 1);
        add_pos(n - x - 1);
        add_pos(n - x + 2);
    }
    // also optionally add middle point(s)
    add_pos((n + 1) / 2);
    if (n >= 2)
        add_pos(n / 2);

    vector<long long> candidates;
    candidates.reserve(cand_set.size());
    for (auto v : cand_set)
        if (v >= 1 && v <= n)
            candidates.push_back(v);
    sort(candidates.begin(), candidates.end());

    ll col_min = LLONG_MAX, col_max = LLONG_MIN;
    for (auto j : candidates)
    {
        ll val = contribL_at(j) + contribR_at(j);
        if (val < col_min)
            col_min = val;
        if (val > col_max)
            col_max = val;
    }
    // It's possible there were no L and no R operations => col_min/col_max should be 0
    if (col_min == LLONG_MAX && col_max == LLONG_MIN)
    {
        col_min = col_max = 0;
    }
    ll col_diff = col_max - col_min;
    cout << (row_diff + col_diff) << '\n';
    return 0;
}