#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,d=0,p1,p2;
    cin >> n;
    bool check=0;
    pair<long long,long long>a[n];
    for(long long i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    for(long long i=0; i<n-1; i++) {
        if(a[i].first==a[i+1].first) {
            d++;
            if(d==1) p1=i;
            if(d==2) p2=i;
        }
        if(d==2) {
            check=1;
            break;
        }
    }
    if(check=0) {
        cout << "NO";
        return 0;
    }
    else {
        cout << "YES" << endl;
        for(long long i=0; i<n; i++) cout << a[i].second+1 << " ";
        cout << endl;
        swap(a[p1],a[p1+1]);
        for(long long i=0; i<n; i++) cout << a[i].second+1 << " ";
        cout << endl;
        swap(a[p2],a[p2+1]);
        for(long long i=0; i<n; i++) cout << a[i].second+1 << " ";
        return 0;
    }
}
