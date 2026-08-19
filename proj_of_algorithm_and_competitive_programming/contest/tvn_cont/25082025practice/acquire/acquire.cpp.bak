#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fi first
#define se second
#define file(n) freopen(n".inp", "r", stdin); freopen(n".out", "w", stdout);
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int maxn=10004,inf=INT_MAX/2;
int n;
pair<int,int>farm[maxn];
bool mk[maxn];
int cal(vector<int>a)
{
    int m1=0,m2=0;
    for(int i:a) {
        m1=max(m1,farm[i].fi);
        m2=max(m2,farm[i].se);
    }
    return m1*m2;
}
bool cmp(pair<int,int>a, pair<int,int>b)
{
    return max(a.fi,a.se)>max(b.fi,b.se);
}
void souprua()
{
    sort(farm+1,farm+1+n,cmp);
    vector<int>a;
    int kq=0;
    int t=0,m1=0,m2=0;
    bool kt=true;
    for(int i=1; i<=n; i++) {
        int t1=max(m1,farm[i].fi),t2=max(farm[i].se,m2);
        int temp=t+farm[i].fi*farm[i].se;
        if(t1*t2+(kt?t:0)>temp) {
            t=temp;
            m1=0;m2=0;
            kt=true;
        }
        else {
            t+=t1*t2-m1*m2;
            m1=t1;m2=t2;
            kt=false;
        }
        //cout << t << " ";
    }
    cout << t;
    //for(int i=1; i<=n; i++) cout << farm[i].fi << " " << farm[i].se << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("acquire");
    cin >> n;
    for(int i=1; i<=n; i++) cin >> farm[i].fi >> farm[i].se;
    souprua();
}
/*
4
100 1
15 15
20 5
1 100
*/
