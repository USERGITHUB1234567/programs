/**/
namespace soup1{
    void solve() {
        long long s = 0;
        vector<pair<long long, long long>> vec;
        vec.reserve(n);
        
        for(int i=1; i<=n; ++i) {
            // Read coordinates into long long to avoid overflow when calculating lengths
            long long l1 = c[i].l1, r1 = c[i].r1;
            long long l2 = c[i].l2, r2 = c[i].r2;
            
            long long L_max = max(l1, l2);
            long long L_min = min(l1, l2);
            long long R_min = min(r1, r2);
            long long R_max = max(r1, r2);
            
            // I: Current intersecting length
            long long I = max(0LL, R_min - L_max);
            s += I;
            
            // D: Gap distance before they start touching (cost to unlock 1-for-1 ratio)
            long long D = max(0LL, L_max - R_min);
            // M: Max union bounding length
            long long M = R_max - L_min;
            // A: Remaining length we can intersect at a 1-to-1 cost ratio
            long long A = M - I;
            
            vec.emplace_back(D, A);
        }
        
        // If we already meet the requirement
        if (s >= k) {
            cout << 0 << "\n";
            return;
        }
        
        long long R = (long long)k - s;
        // Sort pairs by unlocking cost (D) ascending
        sort(vec.begin(), vec.end());
        
        long long ans = 8000000000000000000LL; // Safe Infinity threshold (8e18)
        long long cur_D = 0;
        long long cur_A = 0;
        
        for(int i=0; i<n; ++i) {
            // Option 1: What if we ONLY unlock this single segment pair?
            long long single_cost = vec[i].first;
            if (vec[i].second >= R) {
                single_cost += R;
            } else {
                // If it can't fulfill alone at cost 1, max it out, then pay cost 2 for the remainder
                single_cost += vec[i].second + 2LL * (R - vec[i].second);
            }
            ans = min(ans, single_cost);
            
            // Option 2: What if we unlock a prefix combination of segment pairs?
            cur_D += vec[i].first;
            cur_A += vec[i].second;
            
            long long prefix_cost = cur_D;
            if (cur_A >= R) {
                prefix_cost += R;
            } else {
                prefix_cost += cur_A + 2LL * (R - cur_A);
            }
            ans = min(ans, prefix_cost);
        }
        
        cout << ans << "\n";
    }
}
/**/