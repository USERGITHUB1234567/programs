#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int tc;cin >> tc;
    while(tc--) {
        int n;cin >> n;
        vector<int>v;
        for(int i=1; i<=n; ++i) {int x;cin >> x;v.push_back(x);}
        bool ck=false;
        int cnt=0;
        for(int i:v) {
            if(i>2) ck=true;
            if(i==2) ++cnt;
            //cerr << i << ' ';
        }
        //cout << cnt << '\n';
        cout << ((cnt>1 || ck)?"YES":"NO") << '\n';
    }
}