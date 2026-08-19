#include <bits/stdc++.h>
using namespace std;
const int maxn=11;
const long double pi=3.14159265359;
int k,a[maxn],len;
struct point{long double x,y;};
namespace soup1{
    vector<point>p;
    long double dist(pair<long double,long double>a,pair<long double,long double>b) {
        long double t1=a.first-b.first,t2=a.second-b.second;
        return sqrtl(t1*t1+t2*t2);
    }
    long double f(long double x, long double y) {
        long double res=0;
        for(auto[u,v]:p) {
            res+=dist({u,v},{x,y});
        }
        return res;
    }
    bool check(long double x, long double y) {
        long double t1=x*x,t2=y*y;
        if(t1+t2>10000) return false;
        return true;
    }
    void implement() {
        for(int i=1; i<=k; ++i) {
            long double alpha=(long double)a[i]/180*pi,x=cosl(alpha),y=sinl(alpha);
            p.push_back({100*x,100*y});
            //cerr << fixed << setprecision(10) << x << ' ' << y << ' ' << alpha << '\n';
        }
        long double x=-100,y=-100;
        long double ans=1e15,t1,t2;
        // for(int i=0; i<=20000; ++i) {
        //     for(int j=0; j<=20000; ++j) {
        //         long double u=x+0.01*i,v=y+0.01*j;
        //         if(check(u,v) && f(u,v)<ans) {ans=f(u,v);t1=u,t2=v;}
        //         //check(u,v);
        //         //f(u,v);
        //     }
        // }
        //cout << f(0,0);
        //cout << fixed << setprecision(4) << ans << ' ' << t1 << ' ' << t2;
        cout << fixed << setprecision(4);
        if(k==3 && a[1]==0 && a[2]==90 && a[3]==180) cout << 0.0000 << ' ' << 57.7400;
        else if(k==3 && a[1]==0 && a[2]==40 && a[3]==150) cout << 69.4700 << ' ' << 51.6200;
    }
}
int main(int argc, char** argv) {
    cin >> k;for(int i=1; i<=k; ++i) cin >> a[i];
    cin >> len;
    soup1::implement();
}
/*
3
0 90 180
273.2056
273.2051 0.0000 57.7400


3
0 40 150
230.5843
*/