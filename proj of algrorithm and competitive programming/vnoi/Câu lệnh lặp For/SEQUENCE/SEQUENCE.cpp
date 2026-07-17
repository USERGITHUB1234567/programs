#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n,x,mx=0,ans=0;cin >> n >> x;
    int a[n];
    for(int i=0; i<n; ++i) {cin >> a[i],mx=max(mx,a[i]);}
    for(int i=0; i<n; ++i) {
        int dif=mx-a[i];
        ans+=(dif+x-1)/x;
    }
    cout << ans;
}