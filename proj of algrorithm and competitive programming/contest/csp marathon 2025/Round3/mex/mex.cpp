#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=100005;
int t,m,n;
void soup1() {
    while(t--) {
        cin >> m >> n;
        int a[m][n];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin >> a[i][j];
            }
        }
        vector<int>f[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) f[i][j].push_back(a[i][j]);
                else if(i==0) {
                    f[i][j] = f[i][j-1];
                    f[i][j].push_back(a[i][j]);
                } 
                else if(j==0) {
                    f[i][j] = f[i-1][j];
                    f[i][j].push_back(a[i][j]);
                } 
                else {
                    vector<int>mex1=f[i-1][j],mex2=f[i][j-1];
                    mex1.push_back(a[i][j]);
                    mex2.push_back(a[i][j]);
                    sort(mex1.begin(), mex1.end());
                    sort(mex2.begin(), mex2.end());
                    int k1=0,k2=0;
                    for(int i=0; i<mex1.size()-1; i++) {
                        if(mex1[i+1]-mex1[i]>1) break;
                        k1++;
                    }
                    for(int i=0; i<mex2.size()-1; i++) {
                        if(mex2[i+1]-mex2[i]>1) break;
                        k2++;
                    }
                    if(k1>k2) f[i][j] = f[i-1][j];
                    else f[i][j] = f[i][j-1];
                    f[i][j].push_back(a[i][j]);
                }
                //if(i-2>=0) f[i-2][j].clear();
                //if(j-2>=0) f[i][j-2].clear();
            }
        }
        vector<int>ans=f[m-1][n-1];
        sort(ans.begin(), ans.end());
        int k=0;
        for(int i=0; i<ans.size()-1; i++) {
            if(ans[i+1]-ans[i]>1) break;
            k++;
        }
        cout << k+1 << "\n";
    }
}
/*void soup2() {
    while(t--) {
        cin >> m >> n;
        int a[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cin >> a[i][j];
            }
        }
        int pre[m][n];


    }
}*/
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("mex");
    cin >> t;
    soup1();
}