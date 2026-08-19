#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    int kq=0;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    for(int i=1; i<n; i++) {
        if(a[i]!=a[i-1]) kq++;
    }
    cout << kq+1;
}
