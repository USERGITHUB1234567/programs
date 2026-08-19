#include <bits/stdc++.h>
using namespace std;
int n;string s;
namespace souptrau{
    bool check(int mid) {
        set<string>st;
        for(int i=0; i+mid-1<s.size(); ++i) {
            st.insert(s.substr(i,mid));
        }
        long long t=1;
        for(int i=1; i<=mid; ++i) {
            t*=n;
            cerr << mid << ' ' << t << ' ' << st.size() << '\n';
            if(t>st.size()) return true;
        }
        return false;
    }
    void implement() {
        int l=1,r=s.size();
        while(l<r) {
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        cout << l;
    }
}
namespace soupfull{
    bool mk[26];
    void implement() {
        int ans=1,tmp=0;
        for(char c:s) {
            int id=c-'a';
            if(id<n && !mk[id]) {++tmp;mk[id]=true;}
            if(tmp==n) {
                ++ans;tmp=0;
                for(int i=0; i<n; ++i) mk[i]=false;
            }
        }
        cout << ans;
    }
}
int main(int argc, char** argv) {
    cin >> n >> s;
    //souptrau::implement();
    soupfull::implement();
}