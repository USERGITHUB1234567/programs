#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int tc;cin >> tc;
    while(tc--) {
        int n,k,m;cin >> n >> k >> m;
        if(m<k) cout << "NO\n";
        else {
            cout << "YES\n";
            int a[n+1];
            for(int i=1; i<=n; ++i) {
                if((i-1)%k) a[i]=1;
                else a[i]=m-k+1;
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
    }
}