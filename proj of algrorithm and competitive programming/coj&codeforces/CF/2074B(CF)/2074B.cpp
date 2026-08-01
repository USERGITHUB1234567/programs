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
        long long a[n],t=0;
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a,a+n);
        t=a[0];
        if(n==1) {
            cout << t << "\n";
            continue;
        }
        for(int i=0; i<n-1; i++) {
            t=t+a[i+1]-1;
        }
        cout << t << "\n";
    }
}
