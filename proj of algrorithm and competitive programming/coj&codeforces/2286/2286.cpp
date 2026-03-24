#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,k,a[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=k; i++) {
        int b;
        cin >> b;
        if(binary_search(a+1,a+n+1,b)==1) cout << "YES\n";
        else cout << "NO\n";
    }
}
