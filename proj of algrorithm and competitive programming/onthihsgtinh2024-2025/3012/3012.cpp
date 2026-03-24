#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long k;
    cin >> k;
    long long p=sqrt(k);
    long long ans=k+p;
    p++;
    if(k<p*p and p*p<ans+1) ans++;
    cout << ans;
}
