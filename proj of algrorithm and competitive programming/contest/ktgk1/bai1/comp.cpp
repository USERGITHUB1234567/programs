#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("comp.inp", "r", stdin);
    freopen("comp.out", "w", stdout);
    long long a,b,c;
    cin >> a >> b >> c;
    long long a1=a,b1=b,c1=c;
    b1/=2;
    c1/=4;
    if(a1==0 or b1==0 or c1==0) {
        cout << 0;
        return 0;
    }

    long long t=min({a1,b1,c1});
    cout << t+2*t+4*t;
}
