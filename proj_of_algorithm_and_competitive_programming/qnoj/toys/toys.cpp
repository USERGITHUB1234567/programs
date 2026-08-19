#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
static int f[1<<20], p2[1000005];

static inline int readInt(){
    int c = getchar_unlocked(), x = 0, neg = 0;
    while(c!='-' && (c<'0' || c>'9')) c = getchar_unlocked();
    if(c=='-'){ neg = 1; c = getchar_unlocked(); }
    while(c>='0' && c<='9'){ x = x*10 + (c - '0'); c = getchar_unlocked(); }
    return neg ? -x : x;
}

int main(){
    int n = readInt();
    int m = readInt();
    int FM = 1 << m;

    // Đếm tần suất mask gốc
    for(int i = 0; i < n; i++){
        int k = readInt(), mask = 0;
        while(k--) {
            mask |= 1 << (readInt() - 1);
        }
        f[mask]++;
    }

    // 2^i mod MOD
    p2[0] = 1;
    for(int i = 1; i <= n; i++){
        p2[i] = (p2[i-1] << 1) % MOD;
    }

    // SOS DP: f[mask] = số hộp có submask ⊆ mask
    for(int bit = 0; bit < m; bit++){
        for(int mask = 0; mask < FM; mask++){
            if(mask & (1 << bit)){
                f[mask] += f[mask ^ (1 << bit)];
            }
        }
    }

    // Inclusion–Exclusion
    long long ans = 0;
    int ALL = FM - 1;
    for(int U = 0; U < FM; U++){
        int cntBoxes = f[ALL ^ U];       // số hộp không chứa các type trong U
        int ways     = p2[cntBoxes];      // 2^cntBoxes mod
        if(__builtin_popcount(U) & 1)
            ans = (ans - ways + MOD) % MOD;
        else
            ans = (ans + ways) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
