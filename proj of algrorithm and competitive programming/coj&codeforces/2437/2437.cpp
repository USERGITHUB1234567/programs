#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
int n,m,k,x[200005],y[200005],kq=1e9;
vector<int>b[200005];
signed main()
{
    cin >> n >> m >> k;
    for(int i=1; i<=k; i++) cin >> x[i] >> y[i];
    bool ck1=false,ckm=false;
    for(int i=1; i<=k; i++) {
        if(x[i]==1) {
            ck1=true;
            b[1].push_back(y[i]);
        }
        if(x[i]==n) {
            ckm=true;
            b[n].push_back(y[i]);
        }
        else {
            b[x[i]].push_back(y[i]);
        }
    }
    sort(b[1].begin(),b[1].end());
    sort(b[n].begin(),b[n].end());
    bool ga1=false;
    if(b[1][b[1].size()-1]==m) {
        cout << m+n-1;
        return 0;
    }
    for(int i=2; i<=n-1; i++) {
        if(b[i].size()==0) continue;
        sort(b[i].begin(),b[i].end());
        bool ck=false,ck2=false;
        if(b[i][b[i].size()-1]==m) ck=true;
        for(int j=0; j<b[i].size(); j++) {
            if(binary_search(b[1].begin(),b[1].end(),b[i][j])==1) {
                cout << m+n+1;
                return 0;
            }
        }
    }
    if(!ck1 || !ckm and b[1][b[1].size()-1]!=m) {
        cout << -1;
        return 0;
    }

    for(int i=2; i<=n; i++) {
        vector<int>c1,cm;
        if(i==n) {
            bool ck=false;
            for(int j=0; j<b[n].size(); j++) {
                if(binary_search(b[1].begin(),b[1].end(),b[n][j])==1) {
                    kq=min(kq,m+n+1);
                    ck=true;
                    //break;
                }
            }
            if(ck) break;
        }
        //cout << b[i].size();
        if(b[i].size()==0) continue;
        for(int j=0; j<b[i].size(); j++) {
            if(binary_search(b[1].begin(),b[1].end(),b[i][j])==1) c1.push_back(b[i][j]);
            if(binary_search(b[n].begin(),b[n].end(),b[i][j])==1) cm.push_back(b[i][j]);
        }
        sort(c1.begin(),c1.end());
        sort(cm.begin(),cm.end());
        if(c1.size()>0 and cm[cm.size()-1]==m) {
            kq=min(kq,m+n+1);
            return 0;
        }
        if(c1.size()>0 and cm.size()>0) {
            for(int j:c1) {
                if(binary_search(cm.begin(),cm.end(),j)==1) {
                    cout << m+n;
                    return 0;
                }
            }
        }
        else continue;
        int q1=c1[0],q2=cm[cm.size()-1];
        if(q1<q2) {
            kq=min(kq,m+n+1);
            continue;
        }
        //cout <<
        kq=min(kq,q1+i+abs(q1-q2)+1+(n-i)+1+(m-q2));
    }
    cout << kq;
}
