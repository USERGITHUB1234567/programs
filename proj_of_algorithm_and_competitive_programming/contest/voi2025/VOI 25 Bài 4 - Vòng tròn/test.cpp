#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

long long solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> A(m);
    for (int i = 0; i < m; ++i) cin >> A[i];
    vector<long long> B(k);
    for (int i = 0; i < k; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Hàm tính chi phí di chuyển mảng `vec` vào từng khối liên tiếp bắt đầu tại X trên vòng tròn
    auto get_costs = [&](const vector<long long>& vec) {
        int sz = vec.size();
        auto get_a = [&](int idx) -> long long {
            long long cycle = 0;
            int rem = idx % sz;
            if (rem < 0) rem += sz;
            cycle = (idx - rem) / sz;
            return vec[rem] + cycle * n;
        };

        int offset = 6 * sz;
        int ext_len = 12 * sz;
        vector<long long> a_ext(ext_len);
        for (int i = 0; i < ext_len; ++i) {
            a_ext[i] = get_a(i - offset);
        }

        vector<long long> pref(ext_len + 1, 0);
        for (int i = 0; i < ext_len; ++i) {
            pref[i + 1] = pref[i] + a_ext[i];
        }

        auto get_pref_V = [&](int j, long long p) -> long long {
            int idx_start = j + 1 + offset;
            int idx_end = j + p + offset;
            long long sum_a = pref[idx_end + 1] - pref[idx_start];
            long long sum_k = p * (p + 1) / 2;
            return sum_a - sum_k;
        };

        auto get_V = [&](int j, int idx) -> long long {
            return a_ext[j + idx + offset] - idx;
        };

        // Tìm kiếm nhị phân để tính tổng khoảng cách giá trị tuyệt đối trong thời gian O(log M)
        auto eval_fj = [&](int j, long long X) -> long long {
            int low = 0, high = sz;
            while (low < high) {
                int mid = low + (high - low + 1) / 2;
                if (get_V(j, mid) <= X) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
            long long p = low;
            long long sum_left = get_pref_V(j, p);
            long long sum_right = get_pref_V(j, sz) - sum_left;
            long long cost_left = p * X - sum_left;
            long long cost_right = sum_right - (sz - p) * X;
            return cost_left + cost_right;
        };

        vector<long long> costs(n);
        int j = -2 * sz;
        for (int X = 0; X < n; ++X) {
            while (true) {
                long long c1 = eval_fj(j, X);
                long long c2 = eval_fj(j + 1, X);
                if (c2 <= c1) {
                    j++;
                } else {
                    break;
                }
            }
            costs[X] = eval_fj(j, X);
        }
        return costs;
    };

    vector<long long> CA = get_costs(A);
    vector<long long> CB = get_costs(B);

    vector<long long> CB_ext(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        CB_ext[i] = CB[i % n];
    }

    int window_len = n - k - m + 1;
    deque<int> q;
    for (int i = m; i < m + window_len - 1; ++i) {
        while (!q.empty() && CB_ext[q.back()] >= CB_ext[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    long long min_total = -1;
    for (int x = 0; x < n; ++x) {
        int y_right = x + m + window_len - 1;
        
        // Cập nhật cửa sổ trượt tịnh tiến sang phải
        while (!q.empty() && CB_ext[q.back()] >= CB_ext[y_right]) {
            q.pop_back();
        }
        q.push_back(y_right);

        // Loại bỏ các phần tử nằm ngoài giới hạn cửa sổ
        while (!q.empty() && q.front() < x + m) {
            q.pop_front();
        }

        long long ans = CA[x] + CB_ext[q.front()];
        if (min_total == -1 || ans < min_total) {
            min_total = ans;
        }
    }
    return min_total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (fopen("CYCLE.INP", "r")) {
        freopen("CYCLE.INP", "r", stdin);
        freopen("CYCLE.OUT", "w", stdout);
    } else if (fopen("cycle.inp", "r")) {
        freopen("cycle.inp", "r", stdin);
        freopen("cycle.out", "w", stdout);
    }

    int t;
    if (cin >> t) {
        while (t--) {
            cout << solve() << "\n";
        }
    }
    return 0;
}