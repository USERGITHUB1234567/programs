#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t;
    cin >> t;
    while(t--) {
        long long n,m,r,c;
        cin >> n >> m >> r >> c;
        cout << (m-c)+(n-r)*m+(m-1)*(n-r) << "\n";
    }
    return 0;
}
