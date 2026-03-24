#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k, kq = 0;
    cin >> n >> k;
    vector<pair<long long, long long>> p(n);
    vector<long long> a(k);
    for (long long i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    for (long long i = 0; i < k; i++) cin >> a[i];
    sort(a.begin(), a.end());
    sort(p.begin(), p.end());
    multiset<long long> st;
    long long t = 0;
    for (long long i = 0; i < k; i++) {
        while (t < n && p[t].first <= a[i]) {
            st.insert(p[t].second);
            t++;
        }
        if (!st.empty()) {
            kq += *st.rbegin();
            st.erase(st.find(*st.rbegin()));
        }
    }
    cout << kq;
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k,kq=0;
    cin >> n >> k;
    pair<long long,long long>p[n];
    long long a[k];
    for(long long i=0; i<n; i++) cin >> p[i].first >> p[i].second;
    for(long long i=0; i<k; i++) cin >> a[i];
    sort(a,a+k);
    sort(p,p+n);
    set<long long>st;
    long long t=0;
    for(long long i=0; i<k; i++) {
        //bool c=0;
        while(p[t].first<=a[i] and t<n) {
            //=1;
            st.insert(p[t].second);
            t++;
        }
        if(st.size()>0) {
            kq+=*st.end();
            st.erase(st.end());
        }
    }
    cout << kq;
    //cout << endl;
    //for(long long i=0; i<n; i++) cout << p[i].first << " " <<  p[i].second << "\n";
    //for(long long i=0; i<k; i++) cout << a[i] << " ";
    //set<int>st={1,2,3,4};
    //cout << st.lower_bound(1);
    //long long a[4]={1,2,3,4};
    //cout << *lower_bound(a,a+4,5);
    /*for(long long i=k-1; i>=1; i--) {
        m=0;
        //if(vt==n-1) vt=0;
        while(p[vt].first<=a[i] and vt>=0 and p[vt].first>a[i-1]) {
            m=max(m,p[vt].second);
            vt--;
        }
        p[vt+1].second=0;
        kq+=m;
    }
    long long t=0;
    for(long long i=0; i<=vt; i++) t=max(t,p[i].second);*/
    /*if(k==1) {
        for(long long j=n-1; j>=0; j--) {
                if(p[j].second<=a[0]) {
                    cout << p[j].first;
                    return 0;
                }
            }
    }
    long long d=k,l=0,r=k-1,ma=0,mi=1e18;
    for(long long i=n-1; i>=0; i--) {
        for(long long j=0; j<k; j++) {
            if(a[j]>=p[i].second) {
                kq+=p[i].first;
                a[j]=-1;
            }
        }
    }*/
//}
