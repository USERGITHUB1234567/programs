#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ford(a,b,c) for(int a = b; a <= c; a++)
#define fti(a,b,c) for(int a = b; a >= c; a--)
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define siz size()
#define pll pair<long long,long long>
#define pii pair<int,int>
#define ll long long
#define ms(a,b) for(int i=0;i<=a.siz;i++) a[i]=b;
#define all(a) a.begin(),a.end()
#define pb push_back
#define fi first
#define se second
using namespace std;
int n,q,a[100005];
ll ans;
void sub1(){
    sort(a+1,a+n+1,greater<int>());
    int id=n+1,giam=n/3;
    ford(i,1,n){
        if(i>giam*3) {
            id=i;
            break;
        }
        if(i%3!=0) {
            ans+=a[i];
        }
    }
    ford(i,id,n)
        ans+=a[i];
    cout << ans;
}
ll dp[100005];
void sub2(){
    sort(a+1,a+n+1);
    ford(i,1,n) {
        dp[i]=1e18;
    }
    q=100-q;
    dp[1]=a[1]*q/100;
    dp[2]=(a[1]+a[2])*q/100;
    dp[3]=min((a[1]+a[2]+a[3])*q/100,a[2]+a[3]);
    ford(i,4,n){
        dp[i]=min(dp[i-1]+a[i]*q/100,dp[i-3]+a[i]+a[i-1]);
    }
    cout << dp[n];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    ford(i,1,n) cin >> a[i];
    if(q==0) sub1();
    else sub2();
    return 0;
}