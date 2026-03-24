#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n%2==0) {
            cout << -1 << "\n";
            continue;
        }
        cout << n << " ";
        for(int i=1; i<n; i++) cout << i << " ";
        cout << "\n";
    }
}
