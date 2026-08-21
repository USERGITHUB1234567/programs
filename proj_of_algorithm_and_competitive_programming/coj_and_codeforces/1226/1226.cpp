#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long d=0,n=0;
    map<pair<long long,long long>,long long>kq;
    for(long long i=1; i<=4; i++) {
        long long x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1==x2 and y1==y2) {
            cout << "NO";
            return 0;
        }
        if(x1==x2) d++;
        if(y1==y2) n++;
        kq[{x1,y1}]++;
        kq[{x2,y2}]++;
    }
    if(d!=2 or n!=2) {
            cout << "NO";
            return 0;
    }
    for(auto it=kq.begin(); it!=kq.end(); it++) {
        if(it->second!=2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
