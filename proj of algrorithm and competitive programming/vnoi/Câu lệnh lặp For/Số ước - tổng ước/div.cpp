#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n;cin >> n;
    int ans=0,res=0;;
    for(int i=1; i*i<=n; ++i) {
        if(!(n%i)) {
            ++ans;
            res+=i;
            if(i*i!=n) {++ans;res+=n/i;}
        }
    }
    cout << ans << '\n' << res;
}