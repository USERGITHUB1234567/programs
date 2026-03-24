#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    long double n,rl,r;
    cin >> n >> rl >> r;
    if(rl<r) {
        cout << "NO";
        return 0;
    }
    if(n==1 or (rl-r)*sin(M_PI/n)+1e-15>=r) cout << "YES";
    else cout << "NO";
    return 0;
}
