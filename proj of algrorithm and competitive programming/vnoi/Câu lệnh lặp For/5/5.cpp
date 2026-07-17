#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n,mx=0;cin >> n;
    for(int i=1,x; i<=n; ++i) {cin >> x;mx=max(mx,x);}
    cout << mx;
}