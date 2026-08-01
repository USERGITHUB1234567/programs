#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long x,y,a;
        cin >> x >> y >> a;
        a*=5;
        long long k=x+y;
        if(a%k==0) cout << "YES\n";
        else if(a%k<=x) cout << "NO\n";
        else cout << "YES\n";
    }
}
