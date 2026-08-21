#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=200005;
int n,k,a[maxn];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    vector<int>v;
    for(int i=1; i<=k; i++) v.push_back(a[i]);
    sort(v.begin(),v.end());
    int tv;
    if(k%2==0) tv=(v[k/2]+v[k/2-1])/2;
    else tv=v[k/2];
    for(int i:v) cout << i << " ";
    cout << "\n";

    for(int i=2; i<=n-k+1; i++) {
        v.erase(v.begin());
        v.push_back(a[i+k-1]);
        int tk;
        if(k%2==0) tk=(v[k/2]+v[k/2-1])/2;
        else tk=v[k/2];
        tv=max(tk,tv);
        for(int j:v) cout << j << ' ';
        cout << "\n";
    }
    cout << tv;
}
