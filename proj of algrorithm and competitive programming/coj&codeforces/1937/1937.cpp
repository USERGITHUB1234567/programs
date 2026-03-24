#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long lcm(long long a, long long b) {
    return a*b/__gcd(a, b);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
    long long a,b,x,y;
    cin >> a >> b;
    if(a==b){
        cout << a << " " << b;
        return 0;
    }
    if(a>b) swap(a,b);
    long long g=__gcd(a,b);
    long long l=lcm(a,b);
    long long t=l/g;
    long long bu=1,bv=t;
    long long sq=floor(sqrt((long double)t));
    for(long long i=sq; i>=1; i--){
        if(t%i==0){
            long long u=i,v=t/i;
            if(__gcd(u,v)==1){
                bu=u;
                bv=v;
                break;
            }
        }
    }
    x=g*bu;
    y=g*bv;
    if(x>y) swap(x,y);
    cout << x << " " << y;
    return 0;
}
