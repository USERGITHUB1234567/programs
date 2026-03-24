#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n+1);
    long long ans = 0;
    vector<long long> d(23, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n >= 1)
        d[a[1] % 23]++;
    for(int j = 7; j <= n; j++){
        ans += d[a[j] % 23];
        d[a[j-5] % 23]++;
    }
    cout << ans;
    return 0;
}
