#include <bits/stdc++.h>
using namespace std;
long long pow_mod(long long a, long long b, long long m) {
    long long t=1;
    while (b>0) {
        if (b%2==1) {
            t=(t*a)%m;
        }
        b=b/2;
        a=(a*a)%m;
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t;
    cin >> t;
    while(t--) {
        long long a, b;
        cin >> a >> b;
        cout << pow_mod(a, b, 1e9+7) << "\n";
    }
    return 0;
}
