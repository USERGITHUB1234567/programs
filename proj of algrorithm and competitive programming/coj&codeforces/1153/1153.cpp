#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int a,b;
vector<int>v;
bool kt(int n)
{
    if(n<2) return false;
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    cin >> a >> b;
    for(int i=1; i<=1e5; i++) {
        string m=to_string(i);
        string m1=m;
        reverse(m.begin(),m.end());
        string s1=m1+m;
        string s2=m1;
        m.erase(0,1);
        s2+=m;
        if(kt(stoi(s1)) and stoi(s1)<=b and stoi(s1)>=a) v.push_back(stoi(s1));
        if(kt(stoi(s2)) and stoi(s2)<=b and stoi(s2)>=a) v.push_back(stoi(s2));
        if(stoi(s2)>b) break;
    }
    sort(v.begin(),v.end());
    //cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << "\n";
    }
    return 0;
}
