#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=200005,mod=1e9+7;
string s;
int q,n,pre[30];
char ch[30];
void sup1()
{
    while(q--) {
        char c,d;
        cin >> c >> d;
        for(int i=0; i<s.size(); i++) {
            if(s[i]==c) s[i]=d;
        }
    }
    cout << s;
}
map<int,int>mp;
void trace(int i,int &st)
{
    if(pre[i]==-1) {
        st=i;
        return;
    }
    trace(pre[i],st);
}
int mb[30];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> s >> q;
    for(int i=0; i<30; i++) mb[i]=i;
    memset(pre,-1,sizeof(pre));
    if(s.size()<=5000 && q<=5000) {
        sup1();
        return 0;
    }
    vector<int>v[30];
    for(int i=0; i<s.size(); i++) {
        int t=s[i]-'a';
        v[t].push_back(i);
    }
    while(q--) {
        char c,d;
        cin >> c >> d;
        /*pre[c-'a']=d-'a';
        //c//out << pre[c-'a'] << " ";
        for(int i:v[c-'a']) {
            s[i]=d;
            v[d-'a'].push_back(i);
        }
        v[c-'a'].clear();
        sort(v[d-'a'].begin(),v[d-'a'].end());
        v[d-'a'].erase(unique(v[d-'a'].begin(),v[d-'a'].end()),v[d-'a'].end());*/
        int t1=c-'a',t2=d-'a';
        for(int i=0; i<26; i++) {
            if(mb[i]==t1) mb[i]=t2;
        }
    }
    for(int i=0; i<n; i++) {
        int t=s[i]-'a';
        char c=char(mb[t]+'a');
        s[i]=c;
    }
    cout << s;
}
/*
7
abcdefg
6
g a
e v
f b
d o
b e
a r
*/
