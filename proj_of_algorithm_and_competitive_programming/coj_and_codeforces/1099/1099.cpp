#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a[5],t=0,kq=0,sdu=0;
    bool c2=0;
    for(long long i=0; i<5; i++) {
        cin >> a[i];
    }
    if(a[1]>a[3]) {
        kq+=a[3]*2;
        a[1]-=a[3];
    }
    else {
        kq+=a[1]*2;
        kq+=(a[3]-a[1])*3;
        sdu+=(a[3]-a[1])*3;
        a[1]=0;
    }
    if(a[2]%2==0) {
        kq+=a[2];
    }
    else {
        kq+=a[2]/2;
        //kq+=2;
        //sdu+=2;
        c2=1;
    }
    t=a[1];
    if(c2==1) {
        if(sdu>=2) {
            sdu-=2;
            a[2]=0;
            c2=0;
        }
        if(a[1]>=2 and c2==1) {
            a[1]-=2;
            kq+=4;
        }
        else {
            kq+=2;
            sdu+=2;
        }
    }
    if(a[1]>0) {
        kq+=a[1]%4;
        a[1]-=a[1]%4;
        kq+=a[1]*2-(a[1]/4);
        kq+=min(a[1],sdu/3);
    }
    cout << kq;
}
