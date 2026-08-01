#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n, k,m = 0;
    cin >> n >> k;
    int a[n];
    map<int,int>mp;
    set<int>st;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    mp[a[0]]++;
    m  = max(m, mp[a[0]]);
    int l=0, r=0;
    for(r = 1; r < n; r++) {
        m = max(m, mp[a[r]]);
        mp[a[r]]++;
        while(mp.size()>k+1) {
            mp[a[l]]--;
            if(mp[a[l]]==0) mp.erase(a[l]);
            l++;
        }

        //int len = mp.size();
        //m=max(m,len);
        m = max(m, mp[a[r]]);
        //if(r==n-1) m=max(m,len);
        //cout << m << endl;
    }
    cout << m;
}
