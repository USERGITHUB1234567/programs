#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;
bool isPrime[MAXN];
int cnt[MAXN];

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (!isPrime[i]) continue;
        for (long long j = 1LL * i * i; j < MAXN; j += i) {
            isPrime[j] = false;
        }
    }
    cnt[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        cnt[i] = cnt[i-1] + (isPrime[i] ? 1 : 0);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        int ans = cnt[N] + 1;
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}
