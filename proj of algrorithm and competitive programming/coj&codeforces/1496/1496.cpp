#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    long long n,x,an=0;
    cin >> n >> x;
    /*if(x==1 || x==n*n) {
        cout << 1;
        return 0;
    }*/
    for(long long i=1; i*i<=x; i++) {
        if(x%i==0 && i<=n && (x/i)<=n) {
            an++;
            if(i!=x/i) an++;
            //cout << i << " " << x/i;
        }
    }
    cout << an;
}
