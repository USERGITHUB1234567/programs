#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    long long n,m,a;
    cin >> n >> m >> a;
    long long ng=n/a,d=m/a;
    if(n%a!=0) ng++;
    if(m%a!=0) d++;
    cout << d*ng;
    return 0;
}
