#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long a,b,c,m,t=1;
void modpro()
{
    for(int i=1; i<=b; i++) {
        t*=a;
        t%=m;
    }
}
int main()
{
    cin >> a >> b >> c >> m;
    modpro();
    t/=c;
    cout << t;
}
