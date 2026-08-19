#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int tc;cin >> tc;
    while(tc--) {
        int n,k,p,m,cnt=0;cin >> n >> k >> p >> m;
        vector<int>a(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        while(true) {
            if(p<=k) {
                if(a[p-1]>m) break;
                int val=a[p-1];
                m-=a[p-1];
                a.erase(a.begin()+p-1);
                p=n;
                a.push_back(val);
                ++cnt;
            }
            else {
                int val=a[0],pos=0;
                for(int i=0; i<k; ++i) {
                    if(a[i]<val) {
                        val=a[i];
                        pos=i;
                    }
                }
                if(m<val) break;
                a.erase(a.begin()+pos);
                a.push_back(val);
                m-=val;
                --p;
            }
        }
        cout << cnt << '\n';
    }
}