#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int a[maxn],pre1[maxn],pre2[maxn];
int main(int argc, char** argv) {
    int tc;cin >> tc;
    while(tc--) {
        int n;cin >> n;
        for(int i=1; i<=n; ++i) {
            cin >> a[i];
            pre1[i]=pre1[i-1]+(a[i]==1?1:-1);
            pre2[i]=pre2[i-1]+(a[i]==3?-1:1);
        }
        int mn=2e9;
        bool ck=false;
        for(int i=1; i<n; ++i) {
            if(pre2[i]-mn>=0) {ck=true;break;}
            if(pre1[i]>=0) mn=min(mn,pre2[i]);
        }
        cout << (ck?"YES":"NO") << '\n';
    }
}