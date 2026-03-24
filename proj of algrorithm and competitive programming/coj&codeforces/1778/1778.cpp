#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=100005;
int q,fl;
int cal(int n) {
    int res=0;
    while(n>1) {
        if(n&1) {
            n--;
            n>>=1;
        }
        else n>>=1;
        res++;
    }
    return res;
}
int lca(int u, int v) {
    while(u!=v) {
        if(u<v) swap(u,v);
        if(u&1) {
            u--;
            u>>=1;
        }
        else u>>=1;
    }
    return u;
}
int dist(int u, int v) {
    return cal(u)+cal(v)-2*cal(lca(u,v))+1;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> q;
    while(q--) {
        string t;
        cin >> t;
        int x,y;
        if(t=="Qi") fl^=1;
        else if(t=="Qb") {
            cin >> x >> y;
            int kq;
            int t1=cal(x),t2=cal(y),t3=cal(lca(x,y));
            int d1=(t1+2-fl)/2,d2=(t2+2-fl)/2,d3=(t3+2-fl)/2;
            int ex=(t3%2==fl?1:0);
            kq=d1+d2-2*d3+ex;
            cout << kq << "\n";
        }
        else if(t=="Qr") {
            cin >> x >> y;
            int kq,d=dist(x,y);
            int t1=cal(x),t2=cal(y),t3=cal(lca(x,y));
            int d1=(t1+2-fl)/2,d2=(t2+2-fl)/2,d3=(t3+2-fl)/2;
            int ex=(t3%2==fl?1:0);
            kq=d1+d2-2*d3+ex;
            int red=d-kq;
            cout << red << "\n";
        }
    }
   //cout << dist(6,9);
}