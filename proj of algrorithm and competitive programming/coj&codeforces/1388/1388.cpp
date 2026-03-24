#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n,m,kq=0;
    cin >> n >> m;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    while(m--) {
        int x,y;
        cin >> x >> y;
        kq+=min(a[x-1],a[y-1]);
    }
    cout << kq;
    return 0;
}
