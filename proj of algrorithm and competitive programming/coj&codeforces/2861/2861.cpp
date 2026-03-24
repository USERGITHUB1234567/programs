#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=100005;
bool nt[maxn];
int t,pre[maxn];
long long n,k;
void snt() {
    memset(nt,true,sizeof(nt));
    nt[0]=nt[1]=false;
    for(int i=2; i*i<maxn; i++) {
        if(nt[i]) {
            int j=i*i;
            while(j<maxn) {
                nt[j]=false;
                j+=i;
            }
        }
    }
}
pair<long long,long long> solve(long long x, long long y) {
    long long u=sqrt(x),v=sqrt(y);
    return {pre[u],pre[u]-pre[v]};
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    snt();
    for(int i=2; i<maxn; i++) {
        pre[i]=pre[i-1]+nt[i];
    }
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << solve(n,k).fi << " " << solve(n,k).se << "\n";
    }
}