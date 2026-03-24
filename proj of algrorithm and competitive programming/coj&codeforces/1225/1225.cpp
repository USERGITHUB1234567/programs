#include <bits/stdc++.h>
using namespace std;
int n,score[100001];
string name[100001];
map<string, int>a,b;
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(long long i=1; i<=n; i++) {
        cin >> name[i] >> score[i];
        a[name[i]]+=score[i];
    }
    int m=-1e9;
    for(auto it=a.begin();it !=a.end(); it++) m=max(m,it->second);
    for(int i=1; i<=n; i++) {
        b[name[i]]+=score[i];
        if(a[name[i]]==m and b[name[i]]>=m) {
            cout << name[i];
            break;
        }
    }
}
