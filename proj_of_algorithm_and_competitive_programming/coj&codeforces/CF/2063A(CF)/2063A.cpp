#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long l,r;
        cin >> l >> r;
        if(l==1 and r==1) cout << 1 << "\n";
        else cout << r-l << "\n";
    }
}
