#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=10,t=0,t1;
    long long a[10];
    for(int i=0; i<10; i++) cin >> a[i];
    for(int i=0; i<10; i++) {
        t+=a[i];
        if(t>=100) {
            t1=t-a[i];
            break;
        }
        if(i==9) t1=t-a[i];
    }
    if(abs(t1-100)<abs(t-100)) cout << t1;
    else cout << t;
    return 0;
}
