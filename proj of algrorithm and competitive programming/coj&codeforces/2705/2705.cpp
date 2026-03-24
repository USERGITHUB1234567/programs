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
const int maxn=1000006;
struct room {
    long long x,y,u,v;
}r[maxn];
//pair<long long, long long> p[maxn];
int n,m;
bool check(room a, pair<long long, long long>b) {
    return (a.x<=b.fi && b.fi<=a.u && a.y<=b.se && b.se<=a.v);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> r[i].x >> r[i].y >> r[i].u >> r[i].v;
    }
    while(m--) {
        int kq=0;
        pair<long long,long long>st,en;
        cin >> st.fi >> st.se >> en.fi >> en.se;
        for(int i=1; i<=n; i++) {
            if(check(r[i],st) && check(r[i],en)) continue;
            else if(check(r[i],st) || check(r[i],en)) kq++;

        }
        cout << kq << "\n";

    }
}