#include <bits/stdc++.h>
using namespace std;
int t(int n)
{
    long long d=0;
    while(n>0) {
        d+=n%10;
        n/=10;
    }
    return d;
}
int main()
{
    long long a,b,c,d=0;
    cin >> a >> b >> c;
    vector<long long>v;
    for(long long i=1; i<=81; i++) {
        long long n=b*pow(i,a)+c;
        if(t(n)==i and n<1000000000) {
            d++;
            v.push_back(n);
        }
    }
    if(d==0) {
        cout << d;
        return 0;
    }
    cout << d << endl;
    for(long long i=0; i<v.size()-1; i++) cout << v[i] << " ";
    cout << v[v.size()-1];
}
