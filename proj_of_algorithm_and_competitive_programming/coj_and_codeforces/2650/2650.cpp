#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n,kq=1;
        cin >> n;
        long long a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a,a+n,greater<long long>());
        for(int i=0; i<n; i++) {
            if(a[i]>=i+1) kq=i+1;
            else break;
        }
        cout << kq << "\n";
    }
}
