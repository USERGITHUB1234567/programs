#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    //freopen("adv.inp", "r", stdin);
    //freopen("adv.out", "w", stdout);
    int n;
    cin >> n;
    long long a[n];
    set<long long>v;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        //v.push_back(a[i]);
        v.insert(a[])
    }
    sort(v.begin(),v.end(),greater<long long>());
    for(int i=0; i<n-1; i++) {
        if(a[i]==v[0]) cout << a[i]-v[1] << " ";
        else cout << a[i]-v[0] << " ";
    }
    if(a[n-1]!=v[0]) cout << a[n-1]-v[0];
    else cout << a[n-1]-v[1];
    return 0;
}
