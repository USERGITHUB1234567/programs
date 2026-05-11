#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,d=0;
    cin >> n;
    string s[n];
    for(long long i=0; i<n; i++) cin >> s[i];
    for(long long i=0; i<n; i++) {
        stack<long long>st;
        //char c="1";
        int t=s[i].size();
        for(long long j=0; j<t; j++) {
            if(st.empty()) {
                st.push(s[i][j]);
                continue;
            }
            if(s[i][j]!=st.top()) st.push(s[i][j]);
            else st.pop();
        }
        //cout << st.top();
        //cou<< s[i].size() << endl;
        if(st.empty()) {
            d++;
        }
    }
    cout << d;
}
