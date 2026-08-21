#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int tc;cin >> tc;
    while(tc--) {
        int n,m;cin >> n >> m;
        int a[n+1],b[m+1];
        bool used[n+1];
        for(int i=1; i<=n; ++i) {cin >> a[i];used[i]=false;}
        for(int i=1; i<=m; ++i) cin >> b[i];
        sort(a+1,a+1+n);sort(b+1,b+1+m);
        int l=1,r=2;
        bool ck=true;
        set<int>st;
        //st.insert(a[1]);
        for(int i=1; i<=n; ++i) st.insert(a[i]);
        for(int i=1; i<=m; ++i) {
            //if(l>b[i]) {ck=false;break;}
            while(r<=n && a[r]<b[i]) {
                //if(!used[i]) {st.insert(a[r]);cerr << i << ' ';}
                if(!used[r])st.insert(a[r]);
                ++r;
            }
            if(*st.begin()>b[i] || st.empty()) {ck=false;break;}
            if(a[r]<b[i]) {ck=false;break;}
            used[r]=true;
            ++r;
            st.erase(st.begin());
        }
        cout << (ck?"YES":"NO") << '\n';
    }
}
