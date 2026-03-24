#include <bits/stdc++.h>
using namespace std;
int n, k;
int x[16] = {0};
int d = 0;
void dfs(int i) {
    if (i > k) {
        d++;
        return;
    }
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        dfs(i + 1);
    }
}
void kq(int i) {
    if (i > k) {
        for (int j = 1; j < k; j++)
            cout << x[j] << " ";
        cout << x[k] << "\n";
        return;
    }
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        kq(i + 1);
    }
}
int main() {
    cin >> k >> n;
    dfs(1);
    cout << d << "\n";
    kq(1);
    return 0;
}
