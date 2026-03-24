#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long a,b,c;
        cin >> a >> b >> c;
        if(a>b and a>c) cout << 0 << " ";
        else cout << max(b,c)-a+1 << " " ;
        if(b>a and b>c) cout << 0 << " ";
        else cout << max(a,c)-b+1 << " ";
        if(c>a and c>b) cout << 0 << "\n";
        else cout << max(a,b)-c+1 << "\n";

    }
}
