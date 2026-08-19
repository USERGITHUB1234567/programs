#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n,k,re=0;
vector<long long>t;
int main()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t.push_back(x);
    }
    sort(t.begin()+1,t.end(),greater<long long>());
    //for(int i:t) cout << i << " ";
    for(int i=0; i<t.size(); i++) {
        if(i<=k) {
            re+=t[i];
            //cout << t[i] << " ";
        }
        else re-=t[i];
    }
    cout << re;
}
