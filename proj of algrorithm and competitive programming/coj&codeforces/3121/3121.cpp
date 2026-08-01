#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=62;
long long x,k,comb[maxn][maxn];
void setup() {
    for(int i=0; i<=52; i++) {
        comb[i][i]=comb[0][i]=1;
        for(int j=1; j<i; j++) comb[j][i]=comb[j][i-1]+comb[j-1][i-1];
    }
}
long long order(long long x, int n) {
    long long res=0;
    for(int i=50; i>=0 && n>0; i--) {
        if((x>>i)&1LL) {
            res+=comb[n][i];
            n--;
        }
    }
    return res+1;
}
long long num(long long r, int n) {
    if(r>comb[n][50] || r>1e15) return -1;
    long long res=0;
    for(int i=50; i>=0 && n>0; i--) {
        if(r>comb[n][i]) {
            res^=(1LL<<i);
            r-=comb[n][i];
            n--;
        }
    }
    return (res > 1000000000000000LL ? -1 : res);
} 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    setup();
    while(t--) {
        cin >> x >> k;
        int n=__builtin_popcountll(x);
        cout << num(order(x,n)+k,n) << "\n";
    }

}