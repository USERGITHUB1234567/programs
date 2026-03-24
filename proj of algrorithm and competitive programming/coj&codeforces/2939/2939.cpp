#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    cout << max((a[0]-a[n-1]*(a[1]-a[n-2]),(a[0]-a[n-2])*(a[1]-a[n-1])));
}
