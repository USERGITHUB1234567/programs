#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=500005;
int n,m;
struct trie
{
    struct node
    {
        int child[26];
        int ext,cnt;

    }nodes[maxn];
    int cur;
    trie():cur(0)
    {
        memset(nodes[0].child,-1,sizeof(nodes[0].child));
        nodes[0].ext=nodes[0].cnt=0;
    }
    int newnode()
    {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].ext=nodes[cur].cnt=0;
        return cur;
    }
    void add(string s)
    {
        int pos=0;
        for(char f:s) {
            int c=f-'a';
            if(nodes[pos].child[c]==-1) {
                nodes[pos].child[c]=newnode();
            }
            pos=nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].ext++;
    }
    bool del_rec(int pos, string& s, int i)
    {
        if(i!=s.size()) {
            int c=s[i]-'a';
            bool isdel=del_rec(nodes[pos].child[c],s,i+1);
            if(isdel) nodes[pos].child[c]=-1;
        }
        else nodes[pos].ext--;
        if(pos!=0) {
            nodes[pos].cnt--;
            if(nodes[pos].cnt==0) return true;
        }
        return false;
    }
    void del(string s)
    {
        if(!found(s)) return;
        del_rec(0,s,0);
    }
    bool found(string s)
    {
        int pos=0;
        for(auto f:s) {
            int c=f-'a';
            if(nodes[pos].child[c]==-1) return false;
            pos=nodes[pos].child[c];
        }
        return (nodes[pos].ext!=0);
    }
};
trie t;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        t.add(s);
    }
    cin >> m;
    for(int i=1; i<=m; i++) {
        string s;
        cin >> s;
        cout << t.found(s) << "\n";
    }
}
