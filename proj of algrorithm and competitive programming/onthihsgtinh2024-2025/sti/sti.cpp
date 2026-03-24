#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n,kq=0;
    cin >> n;
    int a[n];
    int d[1005]={0};
    vector<int>v;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        d[a[i]]++;
        if(d[a[i]]==2) v.push_back(a[i]);
        else if(d[a[i]]==4) kq++;
    }
    int t=v.size();
    kq+=(t*(t-1))/2;
    cout << kq << " ";
    sort(v.begin(),v.end());
    if(a[v[v.size()-1]]>=4) {
        cout << pow(v[v.size()-1],2);
        return 0;
    }
    cout << v[t-1]*v[t-2];
    return 0;
}
