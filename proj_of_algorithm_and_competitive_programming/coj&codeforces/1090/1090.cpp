#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c,d,t=0;
    cin >> a >> b >> c >> d;
    t+=a;
    if(d>b) t+=c*(d-b);
    cout << t;
}
