#include <bits/stdc++.h>
using namespace std;
const int maxn=1503;
int n,a[maxn];
int query(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int t;cin >> t;
    return t;
}
mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());
int main(int argc, char** argv) {
    cin >> n;
    int p[n];for(int i=0; i<n; ++i) p[i]=i+1;
    shuffle(p,p+n,generator);
    int id1=p[0],id2=p[1],mx=query(id1,id2);
    for(int i=2; i<n; ++i) {
        int cur=p[i];
        int val=query(cur,id1);
        if(val<mx) a[cur]=val;
        else if(val==mx){
            a[id1]=mx;
            id1=cur;
            mx=query(id1,id2);
        }else {
            a[id2]=mx;
            id2=cur;
            mx=val;
        }
    }
    a[id1]=a[id2]=mx;
    cout << "!";
    for(int i=1; i<=n; ++i) cout << ' ' << a[i];
    cout << endl;
}