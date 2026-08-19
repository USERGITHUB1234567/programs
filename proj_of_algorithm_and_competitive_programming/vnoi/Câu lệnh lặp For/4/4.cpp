#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n;
    long long sum=0;cin >> n;
    for(int i=1,x; i<=n; ++i) {cin >> x;sum+=x;}
    cout << sum;
}