#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=1000006;
long long n,a[maxn],kq=0;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int t1=a[1],t2=a[n],l=1,r=n;
    while(l<r) {
        if(t1<t2) {
            t1+=a[++l];
            kq++;
        }
        else if(t1>t2) {
            t2+=a[--r];
            kq++;
        }
        else {
            l++;
            r--;
            t1+=a[l];
            t2+=a[r];
        }
    }
    cout << kq;
}