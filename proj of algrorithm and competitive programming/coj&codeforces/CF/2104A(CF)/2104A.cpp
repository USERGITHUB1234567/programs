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
        long long t=a+b+c;
        if(t%3!=0 || b>t/3) cout << "NO\n";
        else cout << "YES\n";
    }
}
