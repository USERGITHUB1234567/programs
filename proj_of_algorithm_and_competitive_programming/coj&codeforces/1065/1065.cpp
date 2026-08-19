#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    long long kq=0;
    while(n--) {
        long long x;
        cin >> x;
        if(x>0) kq+=x;
    }
    cout << kq*2;
    return 0;
}
