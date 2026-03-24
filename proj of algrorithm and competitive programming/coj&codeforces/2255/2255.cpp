#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n+1];
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1,a+1+n);
        int x=a[1]*a[n];
        bool ck=true;
        for(int i=1; i<=n/2; i++) {
            int q=a[i]*a[n-i+1];
            if(q!=x) {
                ck=false;
                break;
            }

        }
        if(n%2==1) {
            int q=a[n/2+1]*a[n/2+1];
            if(q!=x) ck=false;
        }
        cout << (ck?x:-1) << "\n";
    }
}
