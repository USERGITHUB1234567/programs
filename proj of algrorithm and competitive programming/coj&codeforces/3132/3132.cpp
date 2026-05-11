#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=100005;
long long n,t,a,b,k[maxn],tr,pre[maxn],res[maxn],mem[maxn];
bool mk[maxn];
void souplo() {
    priority_queue<long long, vector<long long>, greater<long long>>pq;
    tr=a-b;
    long long kq=0,tim=0;
    for(int i=1; i<=n; i++) {
        if(tim+b>t) break;
        ll to=kq;
        //cout << i << " " << tim-tr+a << "\n";
        if(tim+a<=t) {
            pq.push(k[i]);
            tim+=a;
        }
        else if(!pq.empty() &&(tim-tr+a)<=t && k[i]>pq.top()){
            //cout << "ahbdkq" << "\n";
            pq.pop();
            pq.push(k[i]);
            tim=tim-tr+a;
        }
        else {
            tim+=b;
            //cout << i << "\n";
        }
        //cout << i <<  " " << tim << "\n";
        //kq=max(kq,to);
    }
    while(!pq.empty()) {
        kq+=pq.top();
        pq.pop();
    }
    cout << kq;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> t >> a >> b;
    ll tim=t;
    for(int i=1; i<=n; i++) {
        cin >> k[i];
        pre[i]=pre[i-1]+k[i];
    }
    //for(int i=n; i<maxn; i++) pre[i]=pre[i-1];
    for(int i=1; i<=n; i++) {
        int q=tim;
        cout << tim << " " << "\n";
        if(i==n) {
            mem[i]=mem[i-1];
            if(tim>=a) {
                mem[i]=mem[i-1]+k[i];
                
            }
            break;
        }
        q-=b;
        //res[i]=res[i-1];
        mem[i]=mem[i-1];
        if(q<0) break;
        int w1=tim/a,w2=(q/a)+1;
        if(i+w1>n) w1=n-i+1;
        if(i+w2>n) w2=n-i;
        int t1=pre[i+w1-1]-pre[i-1],t2=pre[i+w2]-pre[i];
        //cout << i << " " << t1 << " " << t2 << "\n";
        if(t1>=t2) {
            //res[i]+=k[i];
            mem[i]+=k[i];
            mk[i]=true;
            tim-=a;
        }
        else {
            //res[i]=res[i-1];
            mk[i]=false;
            tim-=b;
        }
    }
    //cout << *max_element(mem+1,mem+n+1);
    long long kq=0;
    for(int i=1; i<=n; i++) cout << mem[i] << " ";
    //cout << kq;
}