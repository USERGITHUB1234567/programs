#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int l,r,d,u;
        cin >> l >> r >> d >> u;
        if(l==r && l==d && l==u) cout << "yes\n";
        else cout << "no\n";
    }
}
