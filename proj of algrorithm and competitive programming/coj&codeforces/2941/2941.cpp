#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
double a[4];
int main()
{
    for(int i=0; i<4; i++) cin >> a[i];
    sort(a,a+4);
    if((a[0]/a[2]+a[1]/a[3])<(a[0]/a[3]+a[1]/a[2])) cout << (int)a[0] << " " << (int)a[2] << " " << (int)a[1] << " " << (int)a[3];
    else cout << (int)a[0] << " " << (int)a[3] << " " << (int)a[1] << " " << (int)a[2];
}
