#include <bits/stdc++.h>
using namespace std;
const int maxn=1003;
int n,s[maxn],p[maxn];
namespace soup1{
    int state[20],ans=0;
    void backtrack(int i) {
        if(i>n) {
            int s1=0,s2=0,m1=0,m2=0;
            for(int i=1; i<=n; ++i) {
                if(state[i]==1) {
                    m1=max(m1,p[i]);
                    s1+=s[i];
                }
                else if(state[i]==2) {
                    m2=max(m2,p[i]);
                    s2+=s[i];
                }
            }
            if(s1==s2) ans=max(ans,abs(m1-m2));
            return;
        }
        for(int j=0; j<3; ++j) {
            state[i]=j;
            backtrack(i+1);
        }
    }
    void implement() {
        backtrack(1);
        cout << ans;
    }
}
namespace soupfullrua{
    int mn[maxn],mx[maxn];
    pair<int,int>player[maxn];
    void implement() {
        int t=0;for(int i=1; i<=n; ++i) {t+=s[i];player[i]={p[i],s[i]};}
        //sort(player+1,player+1+n);
        for(int i=1; i<=t; ++i) {
            mn[i]=2e9;
            mx[i]=0;
        }
        for(int i=1; i<=n; ++i) {
            for(int j=s[i]; j<=t; ++j) {
                if(s[i]==j) {
                    mn[j]=mx[j]=p[i];
                }else {
                    if(mx[j-s[i]]>0) {
                        int can=max(mx[j-s[i]],p[i]);
                        mx[j]=max(mx[j],can);
                    }
                    if(mn[j-s[i]]<2e9) {
                        int can=max(mn[j-s[i]],p[i]);
                        mn[j]=min(mn[j],can);
                    }
                }
            }
        }
        int ans=0;
        for(int i=1; i<=t; ++i) {
            if(mx[i] && mn[i]!=2e9) {
                ans=max(ans,mx[i]-mn[i]);
                //cout << i << ' ' << mx[i] << ' ' << mn[i] << '\n';
            }
        }
        cout << ans;
    }
}
namespace cookedsoup{
    vector<pair<int,int>>player;
    void implement() {
        int total=0;
        for(int i=1; i<=n; ++i) {player.push_back({p[i],s[i]});total+=s[i];}
        sort(player.begin(),player.end(),[](pair<int,int>a,pair<int,int>b) {return a.first>b.first;});
        vector<int>f1(total+1,-2e9),f2((total+1)<<1,-2e9);
        int cur=0;
        for(int i=0; i<n; ++i) {
            auto[v,u]=player[i];
            vector<int>nxt1=f1,nxt2=f2;
            nxt1[u]=max(nxt1[u],v);
            for(int j=0; j<=cur; ++j) {
                if(f1[j]!=-2e9) nxt1[j+u]=max(nxt1[j+u],f1[j]);
            }
            for(int j=0; j<=cur; ++j) {
                if(f1[j]!=-2e9) nxt2[j-u+total]=max(nxt2[j-u+total],f1[j]-v);
            }
            for(int j=-cur; j<=cur; ++j) {
                if(f2[j+total]!=-2e9) {
                    nxt2[j+u+total]=max(nxt2[j+u+total],f2[j+total]);
                    nxt2[j-u+total]=max(nxt2[j-u+total],f2[j+total]);
                }
            }
            cur+=u;
            f1=move(nxt1);
            f2=move(nxt2);
        }
        cout << f2[total];
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //freopen("teams.inp", "r", stdin);
    //freopen("teams.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> s[i];
    for(int i=1; i<=n; ++i) cin >> p[i];
    //if(n<=15)soup1::implement();
    //cout << '\n';
    //else soupfullrua::implement();
    cookedsoup::implement();
}
