#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n;cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    int sum=accumulate(a,a+n,0);
    if(sum%n) {cout << -1;return 0;}
    
    sort(a,a+n);
    int t=sum/n;
    sum=0;
    for(int i=0; i<n; ++i) {
        sum+=abs(a[i]-t);
    }
    cout << (sum>>1);
}
