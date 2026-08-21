#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int tc;cin >> tc;
    while(tc--) {
        int n;cin >> n;
        long long sum=0,cur=0;
        bool ck=true;
        for(int i=1; i<=n; ++i) {
            int x;cin >> x;
            sum+=x;
            cur+=i;
            if(sum<cur) {ck=false;}
        }   
        cout << (ck?"YES":"NO") << '\n';
    }
}