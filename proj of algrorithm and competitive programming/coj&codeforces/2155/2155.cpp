#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    if(n%2==1) cout << a[n/2];
    else {
        cout << a[n/2-1];
    }
    return 0;
}
