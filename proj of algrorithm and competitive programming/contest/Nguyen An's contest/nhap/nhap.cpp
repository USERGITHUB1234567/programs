//(^._.^)ﾉ Meow
//From Truong with love
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define lb long double
#define forr(i,x,y) for(int i=x;i>=y;--i)
#define ford(i,x,y) for(int i=x;i<=y;++i)
#define pb push_back
#define pf push_front
#define vll vector<ll>
#define pll pair<ll,ll>
#define ii pair<int,int>
#define mmb(v,c) memset(v,c,sizeof(v))
#define fi first
#define se second
#define isz(x) x.size()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define __ <<" "<<
#define fiset(x) fixed<<setprecision(x)
#define cach(i,n,c1,c2) (i==n?c1:c2)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
using namespace std;
const int MOD=1e9+7;
const ll inf=1e18;
const lb EPS=1e-15;
const int N=5e5+2;
int minmize(int a,int b){return (a<b?a:b);}
int maxmize(int a,int b){return (a>b?a:b);}
ll Minmize(ll a,ll b){return (a<b?a:b);}
ll Maxmize(ll a,ll b){return (a>b?a:b);}
int n;
struct Trie
{
    struct Node
    {
        Node*child[26];
        int cnt,dp;
        bool exist;
        Node()
        {
            ford(c,0,25)
                child[c]=nullptr;
            cnt=dp=0;
            exist=false;
        }
    };
    vector<Node*>vec;
    Node*root;
    Trie()
    {
        root=new Node();
        vec.pb(root);
    }
    void add_string(string&s)
    {
        Node*p=root;
        for(auto&f:s)
        {
            int c=f-'a';
            if(p->child[c]==nullptr)
            {
                p->child[c]=new Node();
                vec.pb(p->child[c]);
            }
            p=p->child[c];
            ++p->cnt;
        }
        p->exist=true;
    }
    int res()
    {
        int s=0;
        int m=isz(vec);
        for(int i=m-1;i>=0;--i)
        {
            Node*u=vec[i];
            int k=0;
            for(int c=0;c<26;++c)
            {
                Node*v=u->child[c];
                if(v!=nullptr&&v->exist)
                    ++k;
            }
            u->dp=(u->exist?1:0);
            int prv=u->dp;
            for(int c=0;c<26;++c)
            {
                Node*v=u->child[c];
                if(v!=nullptr&&v->exist)
                {
                    s=maxmize(s,u->dp+v->dp+k-2);
                    u->dp=maxmize(u->dp,v->dp+u->exist);
                }
            }
            prv=u->dp;
            u->dp=maxmize(u->dp,u->exist+k);
            if(k>0)
                u->dp=maxmize(u->dp,prv+k-1);
            s=maxmize(s,u->dp);
        }
        return s;
    }
};
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //file("Rima");
    cin>>n;
    Trie trie;
    ford(i,1,n)
    {
        string s;
        cin>>s;
        reverse(all(s));
        trie.add_string(s);
    }
    cout<<trie.res();
    return 0;
}