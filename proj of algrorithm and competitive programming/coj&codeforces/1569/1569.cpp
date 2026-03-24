#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    long long k,n,w;
    cin >> k >> n >> w;
    long long t=(((w+1)*w)/2)*k;
    if(t<=n) cout << 0;
    else cout << t-n;
    return 0;
}
