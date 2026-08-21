#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int t=b/m;
    if(a*m<b) cout << n*a;
    else {
        int h=n/m;
        int kq=0;
        kq+=b*h;
        int q=n-h*m;
        if(a*q<b) kq+=a*q;
        else kq+=b;
        cout << kq;
    }
}
