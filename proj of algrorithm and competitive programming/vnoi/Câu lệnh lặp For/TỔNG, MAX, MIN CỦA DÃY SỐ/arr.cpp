#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n,mx=-1e9,mn=1e9,sum=0;cin >> n;
    //int a[n];
    for(int i=1,x; i<=n; ++i) {
        cin >> x;
        mn=min(mn,x);
        mx=max(mx,x);
        sum+=x;
    }
    cout << sum << '\n' << mx << '\n' << mn;
}