#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int maxn=100005;
int n;
long long k,a[maxn],pr[maxn];
string conv1(long long x)
{
    string s="";
    while(x>0) {
        if(x&1) s='1'+s;
        else s='0'+s;
        x>>=1;
    }
    while(s.size()<32) s='0'+s;
    return s;
}
long long conv2(string s)
{
    long long res=0;
    for(char c:s) {
        if(c=='0') res*=2;
        else res=res*2+1;
    }
    return res;
}
struct trie
{
    int tr[maxn<<5][2],cnt[maxn<<5],ext[maxn<<5][2];
    int cur=0;
    void add(long long x)
    {
        string s=conv1(x);
        int pos=0,j;
        cnt[0]++;
        for(char c:s) {
            j=c-'0';
            if(!tr[pos][j]) tr[pos][j]=++cur;
            cnt[tr[pos][j]]++;
            pos=tr[pos][j];
        }
    }
    long long query(long long x)
    {
        string s=conv1(x);
        long long res=0;
        string sk=conv1(k);
        int j1,j2,t,pos=0;
        bool fir=false;
        for(int i=0; i<s.size(); ++i) {
            j1=s[i]-'0',j2=sk[i]-'0',t=1-j1;
            /*if(j2==0 && !tr[pos][j1] && !fir) {
                //cout << i << " ";
                return 0;
            }
            else if(j2==0 && tr[pos][j1]) {
                pos=tr[pos][j1];
                continue;
            }
            if(j2==1) {
                if(j1==1) fir=true;
                if(!tr[pos][j1]) {
                    pos=tr[pos][t];
                }
                else return cnt[pos][j1];
            }*/
            /*if(!tr[pos][j1] && !tr[pos][t]) return res;
            if(j1<j2) {
                //if(!tr[pos][j1]) return 0;
                res+=cnt[pos][j1];
                if(!tr[pos][t]) return res;
                pos=tr[pos][t];
            }
            else {
                if(j1>j2 && !tr[pos][j1]) return res;
                else if(j1>j2 && tr[pos][j1]) pos=tr[pos][j1];
                else if(j1==j2) {
                    if(j1==1) {
                        res+=cnt[pos][j1];
                        pos=tr[pos][t];
                    }
                    else {
                        if(!tr[pos][j1]) return res;
                        pos=tr[pos][j1];
                    }
                }
            }
        }
        //cout << fir;
        //if(!fir) return 0;
        return res+(sk[sk.size()-1]=='1'?cnt[pos][j1]:0);*/
        for(int i=0; i<32; ++i) {
            int j1=s[i]-'0',j2=sk[i]-'0',t=1-j1;
            if(j2==1) {
                if(tr[pos][j1]) res+=cnt[tr[pos][j1]];
                pos=tr[pos][t];
            }
            else pos=tr[pos][j1];
        }
        return res;
    }
}
}t;
void soup1()
{
    int kq=0;
    for(int i=1; i<=n; ++i) {
        long long t=0;
        for(int j=i; j<=n; ++j) {
            t^=a[j];
            //cout << t << "\n";
            if(t<k) {
                kq++;
                //cout << i << " " << j << '\n';
            }
        }
    }
    cout << kq;
}
void soup2()
{
    t.add(0);
    for(int i=1; i<=n; ++i) pr[i]=pr[i-1]^a[i];
    long long kq=0;
    for(int i=1; i<=n; ++i) {
        kq+=t.query(pr[i]);
        //if(i==3) cout << t.query(pr[i]) << " ";
        //if(t.query(pr[i])==0) cout << i << " ";
        //cout << t.query(pr[i]) << " ";
        t.add(pr[i]);
    }
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("xor")
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    if(n<=1000) {
        soup1();
        return 0;
    }
    //soup1();
    //cout << "\n";
    soup2();
}
