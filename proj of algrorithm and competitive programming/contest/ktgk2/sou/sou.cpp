#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long double pi=M_PI;
int main()
{
    freopen("sou.inp", "r", stdin);
    freopen("sou.out", "w", stdout);
    long double a;
    cin >> a;
    long double r=sqrt(a/pi);
    r*=2.0;
    r+=2.0;
    cout << fixed << setprecision(10) << r*r;
    return 0;
}
