#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n];
    for(long long i=0; i<n; i++) {
        cin >> a[i];
    }
    long long t=-1,vt=0;
    long long m=*max_element(a,a+n);
    for(long long i=0; i<n; i++) {
        if(a[i]==m) {
            vt=i;
            break;
        }
    }
    for(long long i=1; i<n-1; i++) {
        if(a[i]%10==5 and a[i]>a[i+1] and i>vt) t=max(t,a[i]);
    }
    sort(a,a+n,greater<long long>());
    for(long long i=0; i<n; i++) {
        if(t==a[i]) {
            cout << i+1;
            return 0;
        }
    }
    if(t==-1) cout << 0;
}
