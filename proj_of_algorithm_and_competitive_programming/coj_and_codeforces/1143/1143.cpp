#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,vt=0;
    cin >> n;
    long long a[n];
    vector<long long>v1,v2,v3;
    for(long long i=0; i<n; i++) {
        cin >> a[i];
        if(a[i]==1) v1.push_back(i+1);
        if(a[i]==2) v2.push_back(i+1);
        if(a[i]==3) v3.push_back(i+1);
    }
    long long m=min({v1.size(),v2.size(),v3.size()});
    if(m==0) {
        cout << 0;
        return 0;
    }
    cout << m << endl;
    while(m--) {
        cout << v1[vt] << " " << v2[vt] << " " << v3[vt];
        vt++;
        cout << endl;
        /*bool c1=0,c2=0,c3=0;
        for(long long i=0; i<n; i++) {
            if(a[i]==1 and c1==0) {
                cout << i+1 << " ";
                c1=1;
                a[i]=-1;
            }
            if(a[i]==2 and c2==0) {
                cout << i+1 << " ";
                c2=1;
                a[i]=-1;
            }
            if(a[i]==3 and c3==0) {
                cout << i+1 << " ";
                c3=1;
                a[i]=-1;
            }
            if(c1==1 and c2==1 and c3==1) break;
        }
        cout << endl;*/
    }
}
