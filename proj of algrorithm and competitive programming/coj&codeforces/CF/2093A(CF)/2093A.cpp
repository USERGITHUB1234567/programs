#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        if(k==1) {
            cout << "YES\n";
            continue;
        }
        else if(k==2) {
            cout << "NO\n";
            continue;
        }
        if(k%2==1) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
