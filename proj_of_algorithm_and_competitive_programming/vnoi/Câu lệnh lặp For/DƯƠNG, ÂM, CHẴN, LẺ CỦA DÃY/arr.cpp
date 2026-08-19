#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n,pos=0,neg=0,sum=0;cin >> n;
    for(int i=1,x; i<=n; ++i) {
        cin >> x;
        pos+=(x>0);
        neg+=(x<0);
        sum+=(!(x&1)?x:0);
    }
    cout << pos << ' ' << neg << '\n' << sum;
}