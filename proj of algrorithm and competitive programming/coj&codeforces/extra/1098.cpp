#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    string s[n];
    for(long long i=0; i<n; i++) {
        cin >> s[i];
        s[i]+='a';
    }
    vector<string>v;
    for(long long i=0; i<n; i++) {
        string t="";
        //long long a;
        for(long long j=0; j<s[i].size(); j++) {
            if(isalpha(s[i][j])) {
                if(t!="") {
                    //a=stoll(t)
                    while(t[0]=='0' and t.size()>1) t.erase(0,1);
                    v.push_back(t);
                    t="";
                }
            }
            if(isdigit(s[i][j])) t+=s[i][j];
        }
    }
    sort(v.begin(),v.end());
    for(long long i=0; i<v.size()-1; i++) cout << v[i] << "\n";
    cout << v[v.size()-1];
}
