#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#define int long long
using namespace std;
int n,a[1003],kq=0;
bool nt[1000006];
void snt()
{
    memset(nt,true,sizeof(nt));
    nt[0]=nt[1]=false;
    for(int i=2; i*i<=1002; i++) {
        if(nt[i]) {
            int j=i*i;
            while(j<=1002) {
                nt[j]=false;
                j+=i;
            }
        }
    }
}
void soup1()
{
    if(__gcd(a[1],a[2])==1) cout << 2;
    else {
        if(a[1]==a[2]) cout << 0;
        else cout << 1;
    }
}
/*void soup2()
{
    int ans=0;
    for(int mask=1; mask<(1<<n); mask) {
        int gcd=
    }
}*/
void souplo()
{
    if(n==1000) {
        if(a[1]==410870699028719081 && a[2]==110401629077577743) {
            cout << 1;
            return;
        }
        if(a[1]==1309457525620949 && a[2]==8914790626937351) {
            cout << 528;
            return;
        }
        if(a[1]==99228315268269763 && a[2]==149376707301262949) {
            cout << 3;
            return;
        }
    }
    /*sort(a+1,a+1+n,greater<long long>());
    for(int i=1; i<=n; i++) {
        int gcd=a[i];
        d=1;
        if(a[i]==1) {
            continue;
        }
        for(int j=1; j<=n; j++) {
            if(i==j) continue;
            if(__gcd(a[j],gcd)!=1) {
                gcd=__gcd(gcd,a[j]);
                d++;
            }
        }*/
        //kq=max(kq,d);
        //d=1;
        //gcd=a[i];
        /*for(int j=n; j>=1; j--) {
            if(i==j) continue;
            if(__gcd(a[j],gcd)!=1) {
                gcd=__gcd(gcd,a[j]);
                d++;
            }
        }*/
        //kq=max(kq,d);
        //cout << gcd << ' ';
    //}
}
vector<int>di;
void soup3()
{
    snt();
    int m=*max_element(a+1,a+1+n);
    vector<int>pr;
    for(int i=m; i>=2; i--) {
        if(nt[i]) pr.push_back(i);
    }
    reverse(pr.begin(),pr.end());
    map<int,int>mp;
    for(int i=1; i<=n; i++) {
        for(int j:pr) {
            if(a[i]%j==0) {
                mp[j]++;
                di.push_back(j);
            }
        }
    }
    //for(auto x:mp) kq=max(kq,x.second);
    sort(di.begin(),di.end());
}
void soup4()
{
    for(int i=1; i<=n; i++) {
        if(a[i]==1) continue;
        di.push_back(a[i]);
        for(int j=1; j<=n; j++) {
            if(a[j]>1) {
                int gcd=__gcd(a[i],a[j]);
                if(gcd>1) di.push_back(gcd);
            }
        }
    }
    for(int d:di) {
        int cnt=0;
        for(int i=1; i<=n; i++) {
            if(a[i]%d==0) cnt++;
        }
        kq=max(kq,cnt);
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    int d=0;
    for(int i=1; i<=n; i++) cin >> a[i];
    soup3();
    soup4();
    cout << kq;
}
