#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=202;
int n,k,a[maxn];
string s;
map<pair<int,vector<int>>,string>mem;
vector<int>add(vector<int>stk, int v) {
    stk.push_back(v);
    return stk;
}
vector<int>rem(vector<int>stk) {
    stk.pop_back();
    return stk;
}
string add_bigint(string a, string b) {
    if(a.size()<b.size()) swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string res="";
    int carry=0;
    for(int i=0; i<a.size(); i++) {
        int da=a[i]-'0',db=i<b.size()?b[i]-'0':0;
        int sum=da+db+carry;
        carry=sum/10;
        res+=(sum%10)+'0';
    }
    if(carry) res+=carry+'0';
    reverse(res.begin(),res.end());
    return res;
}
string cal(int i, vector<int>stk) {
    if(i>n) return (stk.empty()?"1":"0");
    if(mem.find({i,stk})!=mem.end()) return mem[{i,stk}];
    string res="0";
    if(stk.size()<k && stk.size()+1<=n-i) {
        for(int j=0; j<5; j+=2) {
            res=add_bigint(res,cal(i+1,add(stk,j)));
        }
    }
    if(!stk.empty()) {
        res=add_bigint(res,cal(i+1,rem(stk)));
    }
    mem[{i,stk}]=res;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k >> s;
    s=" "+s;
    for(int i=1; i<=n; i++) {
        if(s[i]=='(') a[i]=0;
        else if(s[i]==')') a[i]=1;
        else if(s[i]=='[') a[i]=2;
        else if(s[i]==']') a[i]=3;
        else if(s[i]=='{') a[i]=4;
        else a[i]=5;
    }
    string ans="1";
    vector<int>stk;
    for(int i=1; i<=n; i++) {
        if(stk.size()<k && stk.size()+1<=n-i) {
            for(int j=0; j<a[i]; j+=2) ans=add_bigint(ans,cal(i+1,add(stk,j)));
        }
        if(!stk.empty() && stk.back()+1<a[i]) ans=add_bigint(ans,cal(i+1,rem(stk)));
        if(a[i]%2==0) stk.push_back(a[i]);
        else stk.pop_back(); 
    }
    cout << ans;
    
}