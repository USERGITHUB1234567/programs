#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<long long> ptnt1(long long n)
{
    vector<long long>v;
    for(int i=2; i*i<=n; i++) {
        while(n%i==0) {
            v.push_back(i);
            n/=i;
        }
    }
    if(n>1) v.push_back(n);
    return v;
}
void subtr(long long n)
{
    int d=0;
    long long f[10];
    f[0]=f[1]=1;
    for(int i=2; i<10; i++) f[i]=f[i-1]+f[i-2];
    vector<long long>v=ptnt1(n);
    vector<vector<long long>> vc;
    if(v.size()==1) {
        if(binary_search(f,f+10,v[0])==1) {
            cout << 1 << "\n";
            return;
        }
        else {
            cout << 0 << "\n";
            return;
        }
    }
    int dk=0;
    for(int i=0; i<v.size(); i++) {
        if(binary_search(f,f+10,v[i])==-1) dk++;
    }
    int ct=0;
    if(dk==0) ct=1;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            long long t=1;
            int dp=dk;
            vector<long long>p;
            for(int k=i; k<=j; k++) {
                t*=v[k];
                p.push_back(v[k]);
                if(binary_search(f,f+10,v[k])==-1) {
                    dp--;
                }
            }
            if(binary_search(f,f+10,t)==1 and dp==0) {
                bool kc=true;
                for(int i=0; i<vc.size(); i++) {
                    if(vc[i]==p) {
                        kc=false;
                        break;
                    }
                }
                if(kc){
                    vc.push_back(p);
                    if(binary_search(f,f+10,n/t)==1 and n/t!=1 and v.size()-p.size()>1) {
                        ct++;
                        //cout << n/t << " " << vc.size() << " " << ct;
                    }
                }
                //cout << i << " " << j << "\n";
            }
        }
    }
    cout << vc.size()+ct << "\n";
}
/*void sub3(long long n)
{
    vector<long long>v=ptnt1(n);
    int d=0;
    set<vector<long long>>st;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {

        }
    }
}*/
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("fib.inp", "r", stdin);
    freopen("fib.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        subtr(n);
    }
    return 0;
}
