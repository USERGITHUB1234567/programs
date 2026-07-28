#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int posans[4003];
void init() {
    for(int i=0; i<ans.size(); ++i) {
        posans[ans[i]]=i;
    }
}
void solve(int n);
int publish(vector<int>r) {
    int res=0;
    vector<int>pos(r.size()+1);
    for(int i=0; i<r.size(); ++i) pos[r[i]]=i;
    for(int i=1; i<=r.size(); ++i) {
        for(int j=1; j<=r.size(); ++j) {
            if(posans[i]<posans[j] && pos[i]>pos[j]) ++res;
        }
    }
    for(int i:r) cerr << i << ' ';
    cerr << res << '\n';
    return res;
}
void answer(vector<int>r) {
    cout << (r==ans?"AC":"WA");
}
int main() {
    int n;cin >> n;
    for(int i=1; i<=n; ++i) {int x;cin >> x;ans.push_back(x);}
    init();
    solve(n);
}