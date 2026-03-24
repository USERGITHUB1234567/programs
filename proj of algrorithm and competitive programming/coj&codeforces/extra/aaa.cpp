#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double t=0;
    double a[n];
    double ti=0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        t+=a[i];
    }
    sort(a,a+n);
    t/=n;
    double q1,q2,q3;
    if(n%2==0) q2=(a[n/2]+a[n/2-1])/2;
    else q2=a[n/2];
    int nu=n/2;
    int nua=nu;
    if(n%2==1) nua++;
    if(nu%2==0) {
        q1=(a[nu/2]+a[nu/2-1])/2;
        q3=(a[nu+nu/2]+a[nu+nu/2-1])/2;
    }
    else {
        q1=a[nu/2];
        q3=a[nu+nu/2];
    }
    for(int i=0; i<n; i++) {
        ti+=pow((a[i]-t),2);
    }
    ti/=n;
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << "trung binh " << t << "\n" << "phuong sai " << ti << "\n" << "do lech chuan " << sqrt(ti) << "\n" << "q1 " << q1 << "\n" << "q2 " << q2 << "\n" << "q3 " << q3;
}
