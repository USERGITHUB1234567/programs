#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, wt;
long long kq = 0;
long long f[3003][3003], v[3003], w[3003];
long long f2[3003], sum_[3003];
vector<long long> a[3003];

void soup1() {
    priority_queue<long long> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(v[i] - 1);
    }
    long long ans = 0;
    for (int i = 1; i <= wt / w[1]; i++) {
        long long x = pq.top(); pq.pop();
        ans += x;
        pq.push(x - 2);
    }
    cout << ans << "\n";
}

void soup3() {
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= wt; j++) {
            for (int k = 1; k * w[i] <= j; k++) {
                f[i][j] = max(f[i-1][j],
                              f[i-1][j - k*w[i]] + k*v[i] - 1LL*k*k);
            }
        }
    }
    // Ví dụ in ra kết quả tối ưu của đầy n loại và sức chứa wt:
    cout << f[n][wt] << "\n";
}

void soup4() {
    for (int i = 1; i <= n; i++)
        a[w[i]].push_back(v[i]);

    for (int W = 1; W <= wt; W++) {
        if (a[W].empty()) continue;

        priority_queue<long long> pq;
        for (auto val : a[W])
            pq.push(val - 1);

        sum_[0] = 0;
        for (int k = 1; k * W <= wt; k++) {
            long long x = pq.top(); pq.pop();
            sum_[k] = sum_[k-1] + x;
            pq.push(x - 2);
        }

        for (int i = wt; i >= 0; i--) {
            for (int k = 0; k * W <= i; k++) {
                f2[i] = max(f2[i], f2[i - k*W] + sum_[k]);
            }
        }
    }
    cout << f2[wt] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> wt;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    soup4();

    return 0;
}
