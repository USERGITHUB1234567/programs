#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    map<string,long long>mp;
    for(long long i=1; i<=n; i++) {
        string s;
        cin >> s;
        if(i==n) {
            mp[s]++;
            if(mp[s]-1==0) cout << "OK";
            else cout << s << mp[s]-1;
        }
        else {
            mp[s]++;
            if(mp[s]-1==0) cout << "OK" << "\n";
            else cout << s << mp[s]-1 << "\n";
        }
    }
}
