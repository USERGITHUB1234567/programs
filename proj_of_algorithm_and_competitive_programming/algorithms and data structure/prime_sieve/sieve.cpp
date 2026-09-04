#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,a[maxn];
vector<int>sieve(int m=1000000) {
    vector<int>prime,mn(m+1,0);
    for(int i=2; i<=m; ++i) {
        if(!mn[i]) {
            mn[i]=i;
            prime.push_back(i);
        }
        for(int p:prime) {
            if(p>mn[i] || i*p>m) break;
            mn[i*p]=p;
        }
    }
    return prime;
}
int main(int argc, char** argv) {
    // cin >> n;
    // for(int i=1; i<=n; ++i) cin >> a[i];
    vector<int>p=sieve(100);for(int i:p) cout << i << ' ';
}