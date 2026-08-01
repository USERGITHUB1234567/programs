#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int s1,s2,s3,s4;
        cin >> s1 >> s2 >> s3 >> s4;
        vector<int>v;
        v.push_back(s1);
        v.push_back(s2);
        v.push_back(s3);
        v.push_back(s4);
        sort(v.begin(),v.end());
        int m1=v[2],m2=v[3];
        int t1=max(s1,s2),t2=max(s3,s4);
        if(t1<t2) swap(t1,t2);
        if(t1==m2 and t2==m1) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
