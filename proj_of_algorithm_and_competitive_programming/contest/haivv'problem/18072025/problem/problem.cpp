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
const int maxn=100005,maxai=1000006;
int n,a[maxn],kq=0;
bool nt[maxai];
void snt() {
    memset(nt,true,sizeof(nt));
    nt[0]=nt[1]=false;
    for(int i=2; i*i<maxai; i++) {
        if(nt[i]) {
            int j=i*i;
            while(j<maxai) {
                nt[j]=false;
                j+=i;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("problem")
    cin >> n;
    snt();
    for(int i=1; i<=n; i++) cin >> a[i];
    int l=1,r=1;
    for(r; r<=n; r++) {
        if(nt[a[r]]) {
            int i=r-l;
            kq+=i*(i+1)/2;
            l=r+1;
        }
    }
    int t=r-l;
    kq+=t*(t+1)/2;
    cout << kq;
}
/*
7
4 6 2 1 4 7 3
*/