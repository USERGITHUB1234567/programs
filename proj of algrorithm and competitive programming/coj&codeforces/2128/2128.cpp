#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=500005,inf=INT_MAX;
int n,q;
struct trie {
    int tr[maxn][26],min_len[maxn];
    int cur;
    trie() {
        memset(tr,-1,sizeof(tr));
        for(int i=0; i<maxn; i++) min_len[i]=inf;
        cur=0;
    }
    int newnode() {
        cur++;
        min_len[cur]=inf;
        memset(tr[cur],-1,sizeof(tr[cur]));
        return cur;
    }
    void add(string s) {
        min_len[0]=min(min_len[0],(int)s.size());
        int pos=0;
        for(char c:s) {
            int j=c-'a';
            if(tr[pos][j]==-1) tr[pos][j]=newnode();
            pos=tr[pos][j];
            min_len[pos]=min(min_len[pos],(int)s.size());
        }
    }
    int calc(string s) {
        int ans=s.size()+min_len[0],pos=0;
        for(int i=0; i<s.size(); i++) {
            char c=s[i];
            int j=c-'a';
            if(tr[pos][j]==-1) break;
            pos=tr[pos][j];
            ans=min(ans,(int)s.size()+min_len[pos]-2*(i+1));
        }
        return ans;
    }
}t;
string s;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> s;
        t.add(s);
    }
    cin >> q;
    for(int i=1; i<=q; i++) {
        cin >> s;
        cout << t.calc(s) << "\n";
    }
}