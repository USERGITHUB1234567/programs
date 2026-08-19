#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
const int MOD = 1e9 + 7;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n + 1), pre(n + 1, 0);
    vector<int> f(MAXN, 0);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 2; i <= n; ++i)
        f[pre[n] - pre[i - 1]] = 1;
    long long kq = 0;
    for (int j = n; j >= 2; --j){
        long long s = pre[n] - pre[j - 1];
        int cnt = 1;
        while (f[(cnt + 1) * s] == 1){
            cnt++;
            if (cnt * s >= 4e5)
                break;
        }
        kq += cnt;
    }
    cout << kq;
    return 0;
}
