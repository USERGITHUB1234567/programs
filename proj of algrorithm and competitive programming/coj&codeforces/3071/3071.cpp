#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        if(x%33==0) cout << "YES\n";
        else cout << "NO\n";
    }
}
