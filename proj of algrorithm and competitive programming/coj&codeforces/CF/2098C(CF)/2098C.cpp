#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
bool kt(long long n)
{
    if(n<2) return false;
    if(n==2) return true;
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long x,k;
        cin >> x >> k;
        if(k==1) {
            if(kt(x)) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        else {
            if(x==1 && k==2) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
    }
}
