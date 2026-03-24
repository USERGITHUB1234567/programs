#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=10000007;
long long sum[maxn];
bool nt[maxn];
void snt() {
    memset(nt,true,sizeof(nt));
    //nt[0]=nt[1]=false;
    for(int i=1; i<maxn; i++) {
        if(nt[i]) {
            int j=i*2;
            while(j<maxn) {
                sum[j]+=i;
                j+=i;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    snt();
    long long a,b;
    cin >> a >> b;
    long long kq=0;
    for(int i=a; i<=b; i++) {
        kq+=abs(sum[i]-i);
    }
    cout << kq;
}