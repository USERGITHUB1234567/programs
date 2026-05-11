#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    //freopen("jum.inp", "r", stdin);
    //freopen("jum.out", "w", stdout);
    long long n,kq=0;
    cin >> n;
    bool ck[n+5],kc[n+5];
    memset(ck,false,sizeof(ck));
    long long a[n+5],b[n+5]={0};
    for(int i=1; i<n; i++) {
        cin >> a[i];
        b[i]=a[i];
        if(a[i]>n) kq=max(kq,a[i]);
    }
    for(int i=1; i<n; i++) {
        long long t=b[i];
        long long v=a[i];
        if(i+v>n) {
            kq=max(kq,t);
        }
        else {
            if(ck[i+v]=false) {
                ck[i+v]=true;
                b[i+v]+=t;
                kq=max(kq,b[i+v]);
                //cout << i+t << " ";
            }
            else {
                b[i+v]=max(b[i+v],t+a[i+v]);
                kq=max(kq,b[i+v]);
            }
        }
    }
    for(int i=0; i<n+5; i++) cout << b[i] << " ";
    //kq=*max_element(b+1,b+n+1);
    //cout << kq;
    return 0;
}
