#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ford(a,b,c) for(int a = b; a <= c; a++)
#define fti(a,b,c) for(int a = b; a >= c; a--)
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define siz size()
#define pll pair<long long,long long>
#define pii pair<int,int>
#define ll long long
#define ms(a,b) memset(a,b,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb(x) push_back
#define fi first
#define se second
using namespace std;
int n,a,b,c,lenn;
ll dp[300][30];
vector<int> s;
void build(int x) {
    s.clear();
    while (x > 0) {
        s.push_back(x % 2);
        x /= 2;
    }
    if (s.empty()) s.push_back(0);
    lenn = s.size();
}
ll solve(int res,int pos) {
    if (pos == lenn) {
        if(res==0) return 1;
        return 0;
    }
    if(dp[res][pos]!=-1) return dp[res][pos];
    ll ans=0;
    ford(x,0,1)
        ford(y,0,1)
            ford(z,0,1) {
                ll num=x*a+y*b+z*c+res;
                if(num%2>a+b+c||num%2!=s[pos]) continue;
                else if(num%2==s[pos]) ans+=solve(num/2,pos+1);
            }
    return dp[res][pos]=ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> a >> b >> c;
        ms(dp,-1);
        build(n);
        cout << solve(0,0) << "\n";
    }
    return 0;
}
