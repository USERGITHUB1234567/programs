#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("wee.inp", "r", stdin);
    freopen("wee.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++) {
        long long t=0;
        for(int j=1; j<=7; j++) {
            long long x;
            cin >> x;
            t+=x;
        }
        cout << t;
        if(i<n) cout << " ";
    }
    return 0;
}
