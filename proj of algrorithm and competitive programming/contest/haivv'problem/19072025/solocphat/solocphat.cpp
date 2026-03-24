#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=200005;
long long n;
ll Akn(ll n, ll k) {
    ll res=1;
    for (ll i=0; i<k; i++) {
        res*=(n-i);
    }
    return res;
}
bool check(long long x) {
    while(x>0) {
        if(x%10==6 || x%10==8) return true;
        x/=10;
    }
    return false;
}
void soup1() {
    int d=0;
    for(int i=1; i<=n/2; i++) {
        if(check(i) || check(n-i)) d++;
    }
    cout << d << "\n";
}
void soupfull() {

}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("solocphat")
    while(cin >> n) {
        soup1();
    }
    //soup1();
}