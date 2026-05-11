#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
set<long long> st;
long long n,k,a,b,pow3[1001];
pair<long long, long long> tk(const set<long long>& s,long long k) {
    pair<long long, long long> p={1e18, 1e18};
    for (long long x:s) {
        if (s.find(x-k)!=s.end()) {
            pair<long long, long long> c={x,x-k};
            if (c<p) {
                p=c;
            }
        }
    }
    return p;
}
void dfs(long long p, long long q) {
    st.insert(q);
    st.insert(p);
    if (abs(p-q) == 1) return;
    dfs(p,(2*p+q)/3);
    dfs((p+2*q)/3,q);
}
void get(long long n, long long k,long long &a,long long &b)
{
    if(n==1) {
        a=0;
        b=k;
        return;
    }
    if(k<=2*pow3[n-1]) get(n-1,k,a,b);
    else {
        if(k<=2*pow3[n-1]) {
            long long a1,b1;
            get(n-1,2*pow3[n-1]-k,a1,b1);
            a=b1;
            b=a1+2*pow3[n-1];
        }
        else {
            get(n-1,k-2*pow3[n-1],a,b);
            b+=2*pow3[n-1];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    long long n, k;
    cin >> n >> k;
    pow3[0]=1;
    for(int i=1; i<=n; i++) {
        pow3[i]=pow3[i-1]*3;
    }
    get(n,k,a,b);
    cout << a << " " << b;
    return 0;
    /*dfs(0,(long long)pow(3,n));
    pair<long long, long long> kq = tk(st, k);
    if (kq.first==1e18 and kq.second==1e18) {
        cout << "Imposible";
    } else {
        if(kq.second>kq.first) swap(kq.second,kq.first);
        cout << kq.second << " " << kq.first;
    }
    return 0;*/

}
