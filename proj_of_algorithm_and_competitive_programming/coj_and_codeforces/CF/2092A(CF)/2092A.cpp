#include <bits/stdc++.h>
#pragma GCC optimze("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        long long k1=*max_element(a,a+n),k2=*min_element(a,a+n);
        cout << k1-k2 << "\n";
    }
}
