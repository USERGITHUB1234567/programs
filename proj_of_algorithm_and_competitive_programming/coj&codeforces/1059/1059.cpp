#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    pair<long long,long long>p[n];
    multimap<long long,long long>mp;
    for(long long i=0; i<n; i++) {
            cin >> p[i].first >> p[i].second;
    }
    long long k;
    cin >> k;
    pair<long long,long long>a[k];
    for(long long i=0; i<k; i++) {
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(a,a+k);
    //sort(p,p+n);
    long long vt=0,d=0,t=0;
    for(long long i=0; i<k; i++) {
        long long ta=0,ng=0,l=0,vt;
        bool c=0;
        for(long long j=0; j<n; j++) {
            if(p[j].first<=a[i].first and p[j].first>=0) {
                if(p[j].second>ta) {
                    ta=p[j].second;
                    vt=j;
                    ng=j;
                    l=a[i].second;
                    //cout << ng+1 << " " << l+1 << " " << ta << " " << p[j].first << " " << p[j].second << endl;
                }
                c=1;
            }
            //if(p[j].first>a[i]) {
                //break;
            //}
        }
        if(c==1) {
            t+=ta;
            d++;
            p[vt].first=-1;
            mp.insert(make_pair(ng+1,l+1));
        }

    }
    cout << d << " " << t << endl;
    //for(long long i=0; i<n; i++) cout << p[i].first << " " << p[i].second << endl;
    for(auto x:mp) {
        cout << x.first << " " << x.second << endl;
    }
}
