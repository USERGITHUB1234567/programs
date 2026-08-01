#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod=2013;
long long n;
int main()
{
    cin >> n;
    long long kq=1;
    kq=((n%mod)*(n%mod)+((4*(n-2))%mod)+1)%mod;
    cout << kq;
}
