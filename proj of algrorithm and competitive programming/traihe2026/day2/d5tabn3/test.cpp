namespace soupfull {
    struct Row {
        long long a, b, c;
    };

    // Sort descending by (Col 1 - Col 2)
    bool cmp(const Row& u, const Row& v) {
        return (u.a - u.b) > (v.a - v.b);
    }

    void solve() {
        vector<Row> v(n);
        long long base_sum = 0;
        
        for (int i = 0; i < n; i++) {
            v[i].a = board[i + 1][0];
            v[i].b = board[i + 1][1];
            v[i].c = board[i + 1][2];
            base_sum += v[i].c;
        }

        // Step 1: Sort the array
        sort(v.begin(), v.end(), cmp);

        // Step 2: Calculate max X elements from the left prefix
        vector<long long> f(n + 1, 0);
        priority_queue<long long, vector<long long>, greater<long long>> pqX;
        long long sumX = 0;

        for (int i = 0; i < n; ++i) {
            long long val = v[i].a - v[i].c;
            if (x > 0) {
                pqX.push(val);
                sumX += val;
                // Keep only the largest `x` elements
                if ((int)pqX.size() > x) {
                    sumX -= pqX.top();
                    pqX.pop();
                }
            }
            // Once we have checked at least x elements, store the optimal sum
            if (i + 1 >= x) {
                f[i + 1] = sumX;
            }
        }

        // Step 3: Calculate max Y elements from the right suffix
        vector<long long> g(n + 1, 0);
        priority_queue<long long, vector<long long>, greater<long long>> pqY;
        long long sumY = 0;

        for (int i = n - 1; i >= 0; --i) {
            long long val = v[i].b - v[i].c;
            if (y > 0) {
                pqY.push(val);
                sumY += val;
                // Keep only the largest `y` elements
                if ((int)pqY.size() > y) {
                    sumY -= pqY.top();
                    pqY.pop();
                }
            }
            // Once we have checked at least y elements, store the optimal sum
            if (n - i >= y) {
                g[i] = sumY;
            }
        }

        // Step 4: Find the maximum total sum across all valid split points `k`
        // We initialize with a sufficiently small number
        long long max_ans = -4e18; 
        for (int k = x; k <= n - y; ++k) {
            max_ans = max(max_ans, base_sum + f[k] + g[k]);
        }

        cout << max_ans << "\n";
    }
}