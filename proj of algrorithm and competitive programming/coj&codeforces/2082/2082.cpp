#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int a,b,h,w;
    cin >> a >> b >> h >> w;
    double t1=double(h)/a,t2=double(w)/b;
    cout << ceil(t1)*ceil(t2);
}
