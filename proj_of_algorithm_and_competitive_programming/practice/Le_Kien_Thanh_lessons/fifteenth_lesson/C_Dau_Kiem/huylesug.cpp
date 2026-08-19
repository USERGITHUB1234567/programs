#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ford(a,b,c) for(int a = b; a <= c; a++)
#define fti(a,b,c) for(int a = b; a >= c; a--)
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define siz size()
#define pll pair<long long,long long>
#define pii pair<int,int>
#define ll long long
#define ms(a,b) for(int i=0;i<=a.siz;i++) a[i]=b;
#define all(a) a.begin(),a.end()
#define pb push_back
#define fi first
#define se second
using namespace std;

int n,head,c,curmx,id,v,c1,c2,mn,nxt,v1,res;
bool isans;
int ans[200005];
vector<int> p,q;

int query(int u,int v){
    cout << "? " << u << " " << v << "\n";
    cout.flush();
    cin >> res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    ford(i,1,n)
        p.pb(i);
    mt19937 rng(1337);
    shuffle(all(p),rng);
    c=p[0];
    curmx=-1;
    ford(i,1,n-1)
        q.pb(p[i]);
    head=0;
    while(head<q.siz){
        id=q[head];
        head++;
        v=query(c,id);
        if(v<curmx){
            ans[id]=v;
            curmx=max(curmx,v);
        }
        else {
            c1=c;
            c2=id;
            mn=v;
            isans=false;
            while(head<q.siz){
                nxt=q[head];
                v1=query(c1,nxt);
                if(v1<mn){
                    ans[nxt]=v1;
                    curmx=max(curmx,v1);
                    head++;
                }
                else if(v1==mn){
                    ans[c1]=mn;
                    curmx=max(curmx,mn);
                    c=c2;
                    isans=true;
                    break;
                }
                else {
                    ans[c2]=mn;
                    curmx=max(curmx,mn);
                    c=c1;
                    head++;
                    c2=nxt;
                    mn=v1;
                }
            }
            if(isans==false){
                ans[c1]=mn;
                ans[c2]=mn;
            }
        }
    }
    cout << "!";
    ford(i,1,n)
        cout << " " << ans[i];
    cout << "\n";
    cout.flush();
    return 0;
}