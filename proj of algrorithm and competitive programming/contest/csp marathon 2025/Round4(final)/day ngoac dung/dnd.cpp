#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=100005;
string s;
bool kt(string s) {
    int v=0,n=0,t=0,g=0;
    bool ck=true;
    for(int k=0; k<=s.size(); k++) {
        if(s[k]=='{') g++;
        else if(s[k]=='}')g--;
        if(s[k]=='(') t++;
        else if(s[k]==')')t--;
        if(s[k]=='<') n++;
        else if(s[k]=='>')n--;
        if(s[k]=='[') v++;
        else if(s[k]==']')v--;
        if(g<0 || t<0 || n<0 || v<0) {
            ck=false;
            break;
        }
    }
    if(g!=0 || t!=0 | n!=0 || v!=0) ck=false;
    return ck;
}
void soup1() {
    int kq=0;
    for(int i=0; i<s.size(); i++) {
        for(int j=i; j<s.size(); j++) {
            //cout << s.substr(i,j-i+1) << "\n";
            //
            if(kt(s.substr(i,j-i+1))) {
                kq=max(kq,j-i+1);
                //cout << i << " " << j << "\n";
            }
        }
    }
    cout << kq;
}
int pre[4][maxn];
void soup2() {
    /*s='*'+s;
    for(int k=1; k<=s.size(); k++) {
        pre[0][k]=pre[0][k-1];
        pre[1][k]=pre[1][k-1];
        pre[2][k]=pre[2][k-1];
        pre[3][k]=pre[3][k-1];
        if(s[k]=='{') pre[0][k]=pre[0][k-1]+1;
        else if(s[k]=='}') pre[0][k]=pre[0][k-1]-1;
        if(s[k]=='(') pre[1][k]=pre[1][k-1]+1;
        else if(s[k]==')') pre[1][k]=pre[1][k-1]-1;
        if(s[k]=='<') pre[2][k]=pre[2][k-1]+1;
        else if(s[k]=='>') pre[2][k]=pre[2][k-1]-1;
        if(s[k]=='[') pre[3][k]=pre[3][k-1]+1;
        else if(s[k]==']')pre[3][k]=pre[3][k-1]+1;
    }
    int kq=0;
    for(int i=1; i<s.size(); i++) {
        for(int j=i+1; j<s.size(); j++) {
            int v=pre[0][j]-pre[0][i-1];
            int n=pre[1][j]-pre[1][i-1];
            int t=pre[2][j]-pre[2][i-1];
            int g=pre[3][j]-pre[3][i-1];
            if(v==0 && n==0 && t==0 && g==0) kq=max(kq,j-i+1);
        }
    }
    cout << kq;*/
    int kq=0;
    for(int i=0; i<s.size(); i++) {
        int v=0,n=0,t=0,g=0;
        for(int j=i; j<s.size(); j++) {
            //cout << s.substr(i,j-i+1) << "\n";
            //
            if(s[j]=='{') g++;
            else if(s[j]=='}')g--;
            if(s[j]=='(') t++;
            else if(s[j]==')')t--;
            if(s[j]=='<') n++;
            else if(s[j]=='>')n--;
            if(s[j]=='[') v++;
            else if(s[j]==']')v--;
            if(g<0 || t<0 || n<0 || v<0) {
                break;
            }
            if(g==0 && t==0 && n==0 && v==0) kq=max(kq,j-i+1);
        }
    }
    cout << kq;
}
int ps3[2][maxn];
void soup3() {
    s='*'+s;
    int kq=0;
    char t1='#',t2;
    if(s[1]=='}' || s[1]==')' || s[1]=='>' || s[1]==']') {
        t2=s[1];
        for(int i=1; i<s.size(); i++) {
            if(s[i]!=t2) {
                t1=s[i];
                break;
            }
        }
    }
    else t1=s[1];
    if(t1=='#') {
        cout << 0;
        return;
    }
    map<int,int>pos;
    for(int i=1; i<s.size(); i++) {
        ps3[0][i]=ps3[0][i-1];
        ps3[1][i]=ps3[1][i-1];
        if(s[i]==t1) ps3[0][i]=ps3[0][i-1]+1;
        else ps3[1][i]=ps3[1][i-1]+1;
        
    }
    cout << kq;
}
void soupfull() {
    int ans=0;
    stack<int>st;
    st.push(-1);
     for(int i=0;i<s.size();i++) {
        if(s[i]=='{' || s[i]=='[' || s[i]=='<' || s[i]=='(') st.push(i);
        else
            if(st.size()>1  && ((s[st.top()]=='(' && s[i]==')') || (s[st.top()]=='[' && s[i]==']') || (s[st.top()]=='{' && s[i]=='}') || (s[st.top()]=='<' && s[i]=='>'))) {
                st.pop();
                ans=max(ans,i-st.top());
            }
            else st.push(i);
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> s;
    map<char,bool>mp;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='[' || s[i]==']') mp['[']=true;
        else if(s[i]=='<' || s[i]=='>') mp['<']=true;
        else if(s[i]=='(' || s[i]==')') mp['(']=true;
        else if(s[i]=='{' || s[i]=='}') mp['{']=true;
    }
    //soup1();
    //cout << "\n";
    //soup2();
    //cout << "\n";
    //soup3();
    soupfull();
}