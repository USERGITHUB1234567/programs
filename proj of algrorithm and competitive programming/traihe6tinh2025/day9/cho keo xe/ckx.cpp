#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
typedef long long ll;
const int maxn=100005;
ll n,k,a[maxn],b[maxn],c[maxn],d[maxn],kq=0;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        int p=(a[i]+k-1)/k;
        c[i]=p*k-a[i];
        kq+=p;
    }
    for(int i=1; i<=n; i++) {
        cin >> b[i];
        int p=(b[i]+k-1)/k;
        d[i]=p*k-b[i];
        kq+=p;
    }
    sort(c+1,c+1+n);
    sort(d+1,d+1+n);
    int j=n;
    for(int i=1; i<=n; i++) {
        if(d[i]+c[j]>=k) {
            kq--;
            j--;
        }
    }
    cout << kq;
    //cout << d;
}