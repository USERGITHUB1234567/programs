#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n,k,t=0;
        cin >> n >> k;
        long long a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a,a+n,greater<long long>());
        for(int i=0; i<k+1; i++) t+=a[i];
        cout << t << "\n";
    }
}
