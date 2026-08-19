#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=200005;
long long n,x,y,a[maxn];
long double esp=1e-12;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> x >> y;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        long long t=a[i];
        t%=(x+y);
        if(t==0) {
            cout << "Both\n";
            continue;
        }
        long double d=0,c=0;
        vector<string>kq;\
        while(t>0) {
            long double u=1.0/x,v=1.0/y;
            if(fabs((d+u)-(c+v))<esp) {
                kq.push_back("Both");
                d+=u;
                c+=v;
                t-=2;
            }
            else if(d+u<c+v) {
                kq.push_back("D");
                d+=u;
                t--;
            }
            else if(d+u>c+v) {
                kq.push_back("C");
                c+=v;
                t--;
            }

        }
        cout << kq[kq.size()-1] << "\n";
    }
}
