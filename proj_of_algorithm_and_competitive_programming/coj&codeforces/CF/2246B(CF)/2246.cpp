#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int tc;cin >> tc;
    while(tc--) {
        int n;cin >> n;
        if(n==2) {cout << "-1\n";}
        else {
            long long sum=6;
            for(int i=1; i<=n; ++i) {
                if(i<=3) cout << i << ' ';
                else {cout << sum << ' ';sum<<=1;}
            }
            cout << '\n';
        }
    }
}