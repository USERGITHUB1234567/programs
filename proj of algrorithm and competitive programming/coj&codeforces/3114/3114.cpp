#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    if(n==2) {
        cout << 1;
        return 0;
    }
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            cout << n/i;
            return 0;
        }
    }
    cout << n;
}