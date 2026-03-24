#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct ca
{
    string n,c,w,s;
};
bool ck(ca a, ca b, ca c)
{
    if(a.n==b.n==c.n
       and a.c==b.c==c.c
       and a.w==b.w==c.w
       and a.s==b.s==c.s) return true;
    if((a.n!=b.n and b.n!=c.n) or (a.c!=b.c and b.c!=c.c) or (a.w!=b.w and b.w!=c.w) or (a.s!=b.s and b.s!=c.s)) return true;
    return false;
}
int main()
{
    int nu,d=0;
    cin >> nu;
    ca a[nu];
    for(int i=0; i<nu; i++) {
        cin >> a[i].n >> a[i].c >> a[i].w >> a[i].s;
    }
    for(int i=0; i<nu; i++) {
        for(int j=i+1; j<nu; j++) {
            for(int k=j+1; k<nu; k++) {
                if(ck(a[i],a[j],a[k])) d++;
            }
        }
    }
    //if(1==1==1) cout << "a";
    cout << d;
}
