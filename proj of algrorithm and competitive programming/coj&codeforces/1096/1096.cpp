#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n,k,de=0;
    cin >> n >> k;
    pair<int,int> a[n];
    vector<int>v;
    vector<pair<int,int>>kt;
    for(int i=0; i<n; i++) {
        cin >> a[i].first;
        //k.push_back(a[i].first);
        a[i].second=i;
    }
    sort(a,a+n);
    while(k--) {
        sort(a,a+n);
        //cout << a[n-1]. first << " " << a[0].first << "\n";
        if(abs(a[n-1].first-a[0].first)<=1) break;
        a[n-1].first--;
        a[0].first++;
        int c=a[n-1].second+1;
        int d=a[0].second+1;
        sort(a,a+n);
        kt.push_back({c,d});
        de++;


    }
    sort(a,a+n);
    cout << a[n-1].first-a[0].first << " " << de << "\n";
    for(int i=0; i<kt.size(); i++) {
        cout << kt[i].first << " " << kt[i].second << "\n";
    }
    return 0;
}
