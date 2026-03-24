#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long
long long modexp(long long b, long long e, long long m)
{
    long long re=1;
    b%=m;
    while(e>0) {
        if(e&1) re=(re*b)%mod;
        b=(b*b)%m;
        e>>=1;
    }
    return re;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        cout << (modexp())
    }
}
