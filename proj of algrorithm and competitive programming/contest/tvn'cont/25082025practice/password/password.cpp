#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fi first
#define se second
#define file(n) freopen(n".inp", "r", stdin); freopen(n".out", "w", stdout);
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int maxn=100005,inf=INT_MAX;
int n,q;
string pass[maxn];
int cal(string s, string t)
{
    int kq=0;
    kq+=abs((int)s.size()-(int)t.size());
    for(int i=0; i<min(s.size(),t.size()); i++) {
        if(s[i]!=t[i]) {
            kq+=2*(min(s.size(),t.size())-i);
            break;
        }
    }
    return kq;
}
void soup1()
{
    while(q--) {
        int res=inf;
        string query;
        cin >> query;
        for(int i=1; i<=n; i++) res=min(res,cal(query,pass[i]));
        cout << res << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("password");
    cin >> n;
    for(int i=1; i<=n; i++) cin >> pass[i];
    cin >> q;
    soup1();

}
/*
3
abc
absicca
fluffy
2
flux
abacus
*/
