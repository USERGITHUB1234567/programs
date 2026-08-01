#include "art.h"
#include <vector>

void solve(int n) {
    std::vector<int> r(n), ans(n), res(n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            r[j] = (i + j) % n + 1;
        }
        ans[i] = publish(r);
    }
    
    for (int i = 0; i < n; ++i) {
        int nxt = ans[(i + 1) % n];
        int pos = (ans[i] - nxt + n - 1) / 2;
        res[pos] = i + 1;
    }
    
    answer(res);
}