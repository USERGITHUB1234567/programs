#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

bool kt(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (kt(s)) {
            cout << s << "\n";
            continue;
        }
        string t="";
        string s1=s;
        reverse(s1.begin(),s1.end());
        bool ck=false;
        string sc=s;
        bool ckc=false;
        int vt=0;
        for(int i=0; i<s.size()/2; i++) {
            if(s[i]!=s1[i] and ck==true) {
                break;
            }
            else if(s[i]!=s1[i] and ck==false) continue;
            if(s[i]==s1[i]) {
                ck=true;
                t+=s[i];
            }
            vt=i;
        }
        if(vt==s.size()/2-1) {
            if(s.size()%2==0) {
                string tt=t;
                reverse(tt.begin(),tt.end());
                t+=tt;
            }
            else {
                t+=s[s.size()/2];
                string tt=t;
                tt.erase(tt.size()-1,1);
                reverse(tt.begin(),tt.end());
                t+=tt;
            }
        }
        cout << t << "\n";
    }
    return 0;
}
