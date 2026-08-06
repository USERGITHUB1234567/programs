#include <bits/stdc++.h>
using namespace std;
const int maxn=1003;
int n,x,h[maxn],s[maxn];
int main(int argc, char** argv) {
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> h[i];
    for(int i=1; i<=n; ++i) cin >> s[i];
    vector<int>dp(x+1,0);
    for(int i=1; i<=n; ++i) {
        for(int c=x; c>=h[i]; --c) {
            dp[c]=max(dp[c],dp[c-h[i]]+s[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}