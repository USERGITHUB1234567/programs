#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(s.size()%2==1) {
            cout << "NO" << endl;
            continue;
        }
        long long n=s.size()/2;
        string s1,s2;
        s1=s.substr(0,n);
        s2=s.substr(n,n);
        if(s1!=s2) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}
