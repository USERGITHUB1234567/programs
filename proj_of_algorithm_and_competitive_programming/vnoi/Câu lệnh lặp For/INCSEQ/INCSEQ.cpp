#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n,mx=0,ans=0;cin >> n;
    int a[n];for(int i=1; i<=n; ++i) {cin >> a[i];mx=max(mx,a[i]);}
    for(int i=1; i<=n; ++i) {ans+=mx-a[i];}
    cout << ans;
}