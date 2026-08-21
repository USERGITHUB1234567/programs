#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=100005;
string s;
int cnt[26];
int cal(string t) {
    map<char,bool>mp;
    for(char c:t) mp[c]=true;
    return mp.size();
}
long long solve(int i) {
    memset(cnt,0,sizeof(cnt));
    long long res=0;
    int dif=0,l=0,r=0;
    for(r; r<s.size(); r++) {
        if(cnt[s[r]-'a']++==0) dif++;
        while(dif>i) {
            if(--cnt[s[l]-'a']==0) dif--;
            l++;
        }
        res+=(r-l+1);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> s;
    int n=cal(s);
    cout << n << "\n";
    for(int i=1; i<=n; i++) {
        cout << solve(i)-solve(i-1) << "\n";
    }
}