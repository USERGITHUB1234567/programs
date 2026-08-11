#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
long long fib[50];
int n,q,a[maxn];
pair<int,int>query[maxn];
namespace soup1{
    bool used[50];
    void implement() {
        for(int t=1; t<=q; ++t) {
            auto[l,r]=query[t];
            int ans=0;
            for(int i=1; i<50; ++i) used[i]=false;
            for(int i=l; i<=r; ++i) {
                for(int j=i+1; j<=r; ++j) {
                    long long sum=a[i]+a[j];
                    int p=lower_bound(fib+1,fib+50,sum)-fib;
                    if(!used[p] && fib[p]==sum) {++ans;used[p]=true;}
                }
            }
            cout << ans << '\n';
        }
    }
}
namespace soupnq{
    bool used[50];
    unordered_map<int,int>cnt;
    array<int,3>qu[maxn];
    long long ans[maxn],cur=0;
    const int block_size=317;
    void add(int i) {
        ++cnt[a[i]];

    }
    void rem(int i) {
        --cnt[a[i]];
    }
    void implement() {
        for(int i=1; i<=q; ++i) {
            auto[l,r]=query[i];
            qu[i][0]=l,qu[i][1]=r,qu[i][2]=i;
        }
        sort(qu+1,qu+1+q,[&](const array<int,3>& a,const array<int,3>& b){
            int bl_a=a[0]/block_size,bl_b=b[0]/block_size;
            return (bl_a<bl_b) || (bl_a==bl_b && a[1]<b[1]);
        });
        int ql=0,qr=-1;
        for(int t=1; t<=q; ++t) {
            auto[l,r,id]=qu[t];
            while(qr<r) add(++qr);
            while(ql<l) rem(ql++);
            while(qr>r) rem(qr--);
            while(ql>l) add(--ql);
            long long res=0;
            //cout << l << ' ' << r << '\n';
            //for(int i=1; i<=10; ++i) cout << cnt[i] << ' ';
            //cout << '\n';
            for(int i=1; i<50; ++i) used[i]=false;
            for(int f=1; f<50; ++f) {
                if(used[f]) continue;
                for(int i=l; i<=r; ++i) {
                    if(fib[f]<=a[i] || used[f]) continue;
                    int z=fib[f]-a[i];
                    if((a[i]==z && cnt[z]>=2) || (a[i]!=z && cnt[z])) {
                        ++res;used[f]=true;
                        //cout << fib[f] << ' ' << f << '\n';
                        //cout << i << ' ' << a[i] << ' ' << z << ' ' << cnt[z] << ' ' << fib[f] << ' ' << f << '\n';
                    }
                }
            }
            //cout << '\n';
            ans[id]=res;
        }
        for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
    }
}
namespace soupfull{
    long long used[50];
    unordered_map<int,int>cnt;
    array<int,3>qu[maxn];
    long long ans[maxn];
    const int block_size=317;
    inline void add(int i) {
        for(int j=1; j<50; ++j) {
            int z=fib[j]-a[i],add=cnt[z];
            //if(!used[j] && (used[j]+add)) ++cur;
            used[j]+=add;
        }
        ++cnt[a[i]];
    }
    inline void rem(int i) {
        --cnt[a[i]];
        for(int j=1; j<50; ++j) {
            int z=fib[j]-a[i],sub=cnt[z];
            //if(used[j]-sub==0) --cur;
            used[j]-=sub;
        }
    }
    void implement() {
        for(int i=1; i<=q; ++i) {
            auto[l,r]=query[i];
            qu[i][0]=l,qu[i][1]=r,qu[i][2]=i;
        }
        sort(qu+1,qu+1+q,[&](const array<int,3>& a,const array<int,3>& b){
            int bl_a=a[0]/block_size,bl_b=b[0]/block_size;
            return (bl_a<bl_b) || (bl_a==bl_b && a[1]<b[1]);
        });
        int ql=0,qr=-1;
        for(int t=1; t<=q; ++t) {
            auto[l,r,id]=qu[t];
            while(qr<r) add(++qr);
            while(ql<l) rem(ql++);
            while(qr>r) rem(qr--);
            while(ql>l) add(--ql);
            //long long res=0;
            //cout << l << ' ' << r << '\n';
            //for(int i=1; i<=10; ++i) cout << cnt[i] << ' ';
            //cout << '\n';
            //for(int i=1; i<50; ++i) cout << used[i] << ' ';
            int res=0;
            for(int i=1; i<50; ++i) res+=(used[i]!=0);
            //cout << '\n';
            ans[id]=res;
        }
        for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
    }
}
namespace cookedsoup{
    int pos[50][maxn];
    void implement() {
        for(int i=1; i<46; ++i) {
            unordered_map<int,int>last;
            int best=-1;
            for(int j=0; j<n; ++j) {
                int z=fib[i]-a[j];
                auto it=last.find(z);
                if(it!=last.end()) best=max(best,it->second);
                pos[i][j]=best;
                last[a[j]]=j;
            }
        }
        for(int t=1; t<=q; ++t) {
            auto[l,r]=query[t];
            int ansv=0;
            for(int i=1; i<46; ++i) ansv+=(pos[i][r]>=l);
            cout << ansv << '\n';
        }
    }

}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("rabit.inp", "r", stdin);
    freopen("rabit.out", "w", stdout);
    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=1; i<=q; ++i) cin >> query[i].first >> query[i].second;
    fib[1]=1,fib[2]=2;
    for(int i=3; i<50; ++i) fib[i]=fib[i-1]+fib[i-2];
    //if(n<=100 && q<=100)soup1::implement();
    //else if(n*q<=1000000) soupnq::implement();
    //else soupfull::implement();
    //cookedsoup::implement();
    soupfull::implement();
}
/*
8 4
7 3 2 10 3 4 1 2
0 5
1 2
4 5
4 7

5 2
14 7 3 2 8
1 2
0 4
*/