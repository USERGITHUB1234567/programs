#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,s;
        cin >> n >> s;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        int m1=*min_element(a,a+n),m2=*max_element(a,a+n);
        int t1=s-m1,t2=m2-s;
        if(t1<0) t1=0;
        if(t2<0) t2=0;
        cout << t1+t2+min(t1,t2) << "\n";
    }
}