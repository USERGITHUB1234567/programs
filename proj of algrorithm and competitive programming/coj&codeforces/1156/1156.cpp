#include <bits/stdc++.h>
using namespace std;
string bd(long long n)
{
    string s;
    while(n>0) {
        if(n%2==0) {
            s="0"+s;
        }
        else s="1"+s;
        n/=2;
    }
    return s;
}
int main()
{
    string d="000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    long long n,t=0;
    cin >> n;
    vector<string>v;
    bool c=1;
    while(c!=0) {
        string s1=bd(t);
        if(s1.size()<=n) {
            string s2=d.substr(0,n-s1.size());
            string s3=s2+s1;
            v.push_back(s3);
            t++;
        }
        else c=0;
    }
    cout << t << "\n";
    for(long long i=0; i<v.size(); i++) cout << v[i] << "\n";
}
