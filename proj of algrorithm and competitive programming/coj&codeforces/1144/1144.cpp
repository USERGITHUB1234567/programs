#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,t1=0,t2=0;
    cin >> n;
    long long a[n];
    vector<long long>v1,v2;
    for(long long i=0; i<n; i++) {
        cin >> a[i];
        if(a[i]>0) {
            v1.push_back(a[i]);
            t1+=a[i];
        }
        else {
            v2.push_back(abs(a[i]));
            t2+=abs(a[i]);
        }
    }
    long long ch;
    bool c=1;
    long long m=min(v1.size(),v2.size());
    for(long long i=0; i<m; i++) {
        if(v1[i]!=v2[i]) {
            c=0;
            if(v1[i]>v2[i]) ch=1;
            else ch=2;
            c=0;
            break;
        }
    }
    if(t1>t2) cout << "first";
    if(t2>t1) cout << "second";
    if(t1==t2) {
        if(c==0) {
            if(ch==1) cout << "first";
            else cout << "second";
        }
        if(c==1) {
            if(v1.size()>v2.size()) {
                cout << "first";
            }
            if(v1.size()<v2.size()) {
                cout << "second";
            }
            if(v1.size()==v2.size()) {
                if(a[n-1]>0) cout << "first";
                if(a[n-1]<0) cout << "second";
            }
        }
    }
}
