#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a[n];
        vector<long long>e,o;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            if(a[i]%2==0) e.push_back(a[i]);
            else o.push_back(a[i]);
        }
        if(e.size()==0 || o.size()==0) {
            cout << *max_element(a,a+n) << "\n";
            continue;
        }
        long long kq=0;
        int i=0;
        int m=min(e.size(),o.size());
        sort(e.begin(),e.end(),greater<long long>());
        sort(o.begin(),o.end(),greater<long long>());
        for(i; i<m; i++) {
            if(i==0) kq+=o[i]+e[i];
            else {
                kq+=o[i]+e[i]-1;
            }
            //if(i==m-1 && o.size()>e.size()) kq++;
        }
        for(i; i<e.size(); i++) kq+=e[i];
        for(int i=m; i<o.size(); i++) kq+=o[i]-1;
        cout << kq << "\n";
    }
}
