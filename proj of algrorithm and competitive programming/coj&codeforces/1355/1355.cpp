#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long m,n;
    cin >> m >> n;
    long long a[n];
    map<long long,long long>mp;
    set<long long>st;
    for(long long i=0; i<n; i++) cin >> a[i];
    long long mi=*min_element(a,a+n);
    long long vt=0;
    mp[a[0]]++;
    st.insert(a[0]);
    for(long long i=1; i<n; i++) {
        for(long long j=mi; j<=a[i]; j++) {
            mp[j]++;
            st.insert(j*mp[j]);
        }
        if(a[i]<a[i-1]) {
            for(long long j=a[i]+1; j<=a[i-1]; j++) mp[j]=0;
        }

        //cout << *prev(st.end()) << endl;
        //for(auto x:mp) cout << x.first << " " << x.second << endl;
    }
    for(long long i=1; i<n; i++) {
        for(long long j=mi; j<=a[i]; j++) {
            mp[j]++;
            st.insert(j*mp[j]);
        }
        if((m-a[i])<(m-a[i-1])) {
            for(long long j=(m-a[i]-1); j<=(m-a[i-1]); j++) mp[j]=0;
        }

        //cout << *prev(st.end()) << endl;
        //for(auto x:mp) cout << x.first << " " << x.second << endl;
    }
    cout << *prev(st.end());
    //cout << endl;

}
