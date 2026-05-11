#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        int x1=0, y1=0;
        for (int i=0; i<n; i++) {
            if(i%2==0) {
                if (a[i]=='1') x1++;
            }
            else {
                if (a[i]=='1') y1++;
            }
            if(i%2==0) {
                if (b[i]=='1') y1++;
            }
            else {
                if (b[i]=='1') x1++;
            }
        }
        int bx=n/2;
        int by=(n+1)/2;
        if (x1<=bx && y1<=by)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
