#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long a,b,c,x,y,kq=0;
int main()
{
    cin >> a >> b >> c >> x >> y;
    if(x>y) {
        long long t=min(a/2,b);
        a-=t*2;
        //b-=b;
        kq+=x*t;
        t=min(a/2,c);
        //a-=t;
        kq+=y*t;
    }
    else {
        long long t=min(a/2,c);
        a-=t*2;
        kq+=y*t;
        t=min(a/2,b);
        kq+=x*t;
    }
    cout << kq;
}
