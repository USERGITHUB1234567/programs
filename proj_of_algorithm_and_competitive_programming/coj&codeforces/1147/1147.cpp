#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int k, n, cnt=0;
vector<long long> v;
void dfs(vector<long long>& v2, int i, long long t) {
    if (i>=k-1) {
        if (t%v[i]==0) {
            v2[i]=t/v[i];
            for (int j=0; j<k-1; j++) {
                cout << v2[j] << " ";
            }
            cout << v2[k-1];
            cout << "\n";
            cnt++;
        }
        return;
    }
    for (int j=0; j*v[i]<=t; j++) {
        v2[i]=j;
        dfs(v2, i+1, t-j*v[i]);
    }
}
int main() {
    cin >> k >> n;
    v.push_back(1);
    for (int i=1; i<k; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    vector<long long> v2(k,0);
    dfs(v2,0,n);
    cout << cnt;
    return 0;
}
