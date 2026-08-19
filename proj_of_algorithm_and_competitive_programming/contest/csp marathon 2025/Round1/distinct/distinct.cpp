#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
string s;
long long kq=0;
void sub1()
{
    map<string,int>mp;
    for(int i=0; i<s.size(); i++) {
        for(int j=i; j<s.size(); j++) {
            map<char,bool>mp2;
            string t="";
            for(int k=i; k<=j; k++) {
                if(!mp2[s[k]]) {
                    t+=s[k];
                    mp2[s[k]]=true;
                }
            }
            sort(t.begin(),t.end());
            mp[t]++;
        }
    }
    cout << mp.size()+1;
}
void sub2()
{
    map<string,bool>mp;
    for(int i=0; i<s.size(); i++) {
        string t="";
        map<char,bool>mp2;
        for(int j=i; j>=0; j--) {
            if(!mp2[s[j]]) {
                t+=s[j];
                sort(t.begin(),t.end());
                mp2[s[j]]=true;
            }
                if(!mp[t]) mp[t]=true;
        }
    }
    cout << mp.size()+1;
    //for(auto x:mp) cout << x.first << "\n";
}
void sub4()
{
    map<string,bool>mp;
    int a[26][26];
    vector<int>v;
    string t="";
    for(int i=0; i<s.size(); i++) {
        if(t!="") {
            for(int j=0; j<t.size(); j++) {
                if(t[j]==s[i]) {
                    t.erase(j,1);
                    j--;
                }
                if(t=="") break;
            }
        }
        string q="";
        t+=s[i];
        for(int j=t.size()-1; j>=0; j--) {
            q+=t[j];
            sort(q.begin(),q.end());
            if(!mp[q]) mp[q]=true;
            //cout << q << "\n";
        }
    }
    cout << mp.size()+1;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("distinct.inp", "r", stdin);
    freopen("distinct.out", "w", stdout);
    cin >> s;
    sub4();
}
