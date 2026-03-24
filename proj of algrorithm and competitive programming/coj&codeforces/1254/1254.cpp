#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    long long a[n];
    for(long long i=0; i<n; i++) cin >> a[i];
    set<long long>st;
    map<long long,long long>mp;
    long long m,p=1;
    for(long long i=0; i<k; i++) {
        st.insert(a[i]);
        mp[a[i]]++;
    }
    m=st.size();
    //cout << m << endl;
    for(long long i=1; i<n-k+1; i++) {
        /*if(st.size()==k) {
            cout << p;
        return 0;
        }*/
        mp[a[i-1]]--;
        if(mp[a[i-1]]==0) st.erase(a[i-1]);
        mp[a[i+k-1]]++;
        st.insert(a[i+k-1]);
        long long t=st.size();
        if(t>m) {
            m=t;
            p=i+1;
            //cout << "a";
        }
        //cout << t << " ";
        //for(auto x:st) cout << x << " ";
        //cout << endl;
    }
    cout << p;
    //cout << m;
    //for(auto x:st) cout << x << " ";
}
