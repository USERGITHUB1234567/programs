#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long kt(long long l, long long r, long long d)
{
    for(long long i=1; i*d<=r*2; i++) {
        if((i*d<l or i*d>r)) return i*d;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q;
    cin >> q;
    while(q--) {
        long long l,r,d;
        cin >> l >> r >> d;
        cout << kt(l,r,d) << "\n";
    }
}
