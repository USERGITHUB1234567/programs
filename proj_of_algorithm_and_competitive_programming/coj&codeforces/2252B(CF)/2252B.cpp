#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int tc;cin >> tc;
    while(tc--) {
        int n;string s;
        cin >> n >> s;
        int tmp=0,ans=0,cnt=0,del1=0,del0=0;
        for(int i=0; i<s.size(); ++i) {
            cnt+=(s[i]=='1');
            if(s[i]=='1') ++tmp;
            else --tmp;
            if(i>0 && s[i]==s[i-1]) {
                if(s[i]=='1') ++del1;
                else ++del0;
            }
        }
        if(abs(tmp)>2) {cout << "-1\n";}
        else {
            int ans=max({0,del1+del0,del1*2-1,del0*2-1});
            cout << ans << '\n';
        }
    }
}