#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,t=0;
    cin >> n;
    map<long long,long long>mp;
    queue<long long>q;
    while(n--) {
        char c;
        cin >> c;
        if(c=='+') {
            long long k;
            cin >> k;
            q.push(k);
            t+=k;
            mp[k]++;
        }
        if(c=='-') {
            t-=q.front();
            mp[q.front()]--;
            q.pop();
        }
        if(c=='?') {
            long long a=t/q.size();
            if(a*q.size()<t) {
                cout << 0 << "\n";
                continue;
            }
            cout << mp[t/q.size()] << "\n";
        }
    }
}
