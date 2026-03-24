#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long m,k;
bool ck(long long n, long long k)
{
    long long d=__builtin_popcount(n);
    if(d==k) return true;
    return false;
}
void soup()
{
    for(int i=m; i<=1e18; i++) {
        int d=0;
        for(int j=i+1; j<=2*i; j++) {
            if(ck(j,k)) d++;
        }
        if(d==m) {
            cout << i;
            break;
        }
    }
}
int main()
{
    cin >> m >> k;
    soup();
    return 0;
}
