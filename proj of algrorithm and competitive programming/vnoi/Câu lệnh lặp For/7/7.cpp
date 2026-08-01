#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n;cin >> n;
    int cnt=0;
    for(int i=1,x; i<=n; ++i) {cin >> x;if(!(x&1)) ++cnt;}
    cout << cnt;
}