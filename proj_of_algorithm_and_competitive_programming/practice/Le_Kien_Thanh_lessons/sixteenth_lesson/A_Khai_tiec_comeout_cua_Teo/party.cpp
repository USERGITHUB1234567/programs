#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,b[maxn],ans[maxn];
int main(int argc, char** argv) {
    cin >> n;
    vector<pair<int,int>>store;
    store.reserve(n+1);
    for(int i=1,a; i<=n+1; ++i) {
        cin >> a;
        store.push_back({a,i});
    }
    for(int i=1; i<=n; ++i) cin >> b[i];
    sort(b+1,b+1+n);
    sort(store.begin(),store.end());
    multiset<int>st;
    for(int i=1; i<=n; ++i) {
        st.insert(max(0,store[i].first-b[i]));
    }
    //cout << *st.rbegin() << ' ';
    ans[store[0].second]=*st.rbegin();
    int pre=store[0].first;
    for(int i=1; i<=n; ++i) {
        int t=max(0,store[i].first-b[i]);
        st.erase(st.find(t));
        t=max(0,pre-b[i]);
        st.insert(t);
        ans[store[i].second]=*st.rbegin();
        pre=store[i].first;
    }
    for(int i=1; i<=n+1; ++i) cout << ans[i] << ' ';
}