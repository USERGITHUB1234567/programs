#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int inf=1e9;
int d[30][30];
int bt[30][30];
map<char,int>p;
vector<int>tr[30][30];
string s,t;
int q;
void floydwarshall(int n)
{
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(d[i][k]!=inf and d[k][j]!=inf) {
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    for(int i=1; i<=26; i++) {
        for(int j=1; j<=26; j++) {
            if(i==j) d[i][j]=0;
            else d[i][j]=inf;
            bt[i][j]=-1;
        }
    }
    cin >> s >> t >> q;
    string m="abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<m.size(); i++) {
        p[m[i]]=i+1;
    }
    for(int i=1; i<=q; i++) {
        char a,b;
        int w;
        cin >> a >> b >> w;
        int pa=p[a],pb=p[b];
        d[pa][pb]=min(d[pa][pb],w);
        //d[pb][pa]=min(d[pb][pa],w);
    }
    if(s.size()!=t.size()) {
        cout << -1;
        return 0;
    }
    floydwarshall(26);
    int kq=0;
    string re="";
    for(int i=0; i<s.size(); i++) {
        if(s[i]==t[i]) {
            re+=s[i];
            continue;
        }
        int l=p[s[i]],r=p[t[i]];
        if(d[l][r]==inf and d[r][l]==inf) {
            cout << -1;
            return 0;
        }
        else {
            int c,be=inf;
            if(d[l][r]!=inf) {
                c=r;
                be=d[l][r];
            }
            if(d[r][l]!=inf) {
                c=min(c,l);
                be=min(be,d[r][l]);
            }
            for(int j=1; j<=26; j++) {
                if(d[l][j]!=inf and d[r][j]!=inf) {
                    int to=d[l][j]+d[r][j];
                    if(to<be) {
                        be=to;
                        c=j;
                    }
                    if(to==be) {
                        c=min(c,j);
                    }
                }
            }
            re+=m[c-1];
            kq+=min(d[l][r],d[r][l]);
        }
    }
    cout << kq << "\n" << re;
}
