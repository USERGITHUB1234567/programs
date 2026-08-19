#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=100005;
struct trie {
    struct node {
        int child[26];
        int cnt,dp;
        bool ext;
        node() {
            for(int i=0; i<26; i++) child[i]=-1;
            cnt=dp=0;
            ext=false;
        }
    };
    vector<node>vec;
    int root;
    trie() {
        root=0;
        vec.push_back(node());
    }
    void add_string(string s) {
        int p=root;
        for(auto f:s) {
            int c=f-'a';
            if(vec[p].child[c]==-1) {
                vec[p].child[c]=vec.size();
                vec.push_back(node());
            }
            p=vec[p].child[c];
            vec[p].cnt++;
        }
        vec[p].ext=true;
    }
    int query() {
        int s=0;
        int m=vec.size();
        for(int i=m-1; i>=0; i--) {
            node& u=vec[i];
            int k=0;
            for(int c=0; c<26; c++) {
                node& v=vec[u.child[c]];
                if(v.child[c]!=-1 && v.ext) {
                    s=max(s,v.cnt);
                    
                }
            }
            u.dp=k;
            if(u.ext) {
                s=max(s,k);
            }
        }
        return s;
    }
} t;
bool check(string s, string t) {
    if(abs((int)s.size()-(int)t.size())>1) return false;
    if(s.size()<t.size()) swap(s,t);
    if(t.size()<s.size() )t+='0';
    //bool ck=true;
    for(int i=1; i<s.size(); i++) {
        if(s[i]!=t[i]) return false;
    }
    return true;
}
string s[maxn];
int n;
void soup1() {
    int kq=0;
    for(int mask=0; mask<(1<<n); mask++) {
        vector<string>v;
        for(int i=0; i<n; i++) {
            if(mask&(1<<i)) v.push_back(s[i]);
        }
        sort(v.begin(), v.end());
        bool ck=true;
        for(int i=1; i<v.size(); i++) {
            ck=check(v[i], v[i-1]);
            if(!ck) break;
        }
        if(ck) {
            kq=max(kq,(int)v.size());
        }
        cout << "\n";
    }
    cout << kq;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) {
        string x;
        cin >> x;
        reverse(x.begin(), x.end());
        t.add_string(x);
    }
    cout << t.query();
    //soup1();
}