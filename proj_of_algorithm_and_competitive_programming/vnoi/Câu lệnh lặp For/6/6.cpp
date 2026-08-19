#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n,mn=INT_MAX;cin >> n;
    for(int i=1,x; i<=n; ++i) {cin >> x;mn=min(mn,x);}
    cout << mn;
}