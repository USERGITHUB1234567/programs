#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n;
    cin >> n;
    int kq=1e9;
    for(int i=1; i<=n; i++) {
        int x,y;
        cin >> x >> y;
        kq=min(kq,y/x);
    }
    cout << kq;
    return 0;
}
