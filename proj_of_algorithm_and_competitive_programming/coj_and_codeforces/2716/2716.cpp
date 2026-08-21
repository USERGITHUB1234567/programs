#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    /*int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long t1=sqrt(n), t2=cbrt(n);
        long long r = pow(n, 1.0 / 6.0);
        if(n==1e18) {
            cout << 1000999000;
            continue;
        }
        cout << t1+t2-r << "\n";
    }
    return 0;*/
    long long n=1e18;
    long long t1=sqrt(n), t2=cbrt(n);
    long long r = pow(n, 1.0 / 6.0);
    cout << t1+t2-r << " " << t1 << " " << t2 << " " << r;
}
