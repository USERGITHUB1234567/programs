#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=100005;
int n,a[maxn],kq=0;
stack<int>st;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    st.push(0);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        while(st.top()>a[i]) {
            //st.push(a[i]);
            st.pop();
        }
        while(st.top()<a[i]) {
            kq++;
            st.push(a[i]);
        }
    }
    cout << kq;
}