#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int m,a,b,c;
        cin >> m >> a >> b >> c;
        int r=c;
        r+=min(m,a);r+=min(m,b);
        cout << r << "\n";
    }
    return 0;
}
