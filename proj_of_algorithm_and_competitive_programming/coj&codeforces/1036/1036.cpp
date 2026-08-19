#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    int n, p,ct=1e9,cp=0;
    cin >> n >> p;
    int a[n],t=0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        t+=a[i];
        if(a[i]==0) {
            ct=min(ct,i);
            cp=max(cp,i);
        }
    }
    int hp=n-p;
    cout << min(hp,p-1)+n-1+t;
    cout << " " << t;
}
