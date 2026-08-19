#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n;cin >> n;
    int a[n],b[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    int ans=0;
    for(int i=0; i<n; ++i) ans+=min(a[i],b[i]);
    cout << ans;
}