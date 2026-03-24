#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 3;
int con[MAX], n, m, it, l[MAX], r[MAX], ll, rr;
stack <int> st;
string s;
char ch;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> it >> s;
    for (int i = 1; i <= n; i++){
        if (s[i - 1] == '(')
            st.push(i);
        else{
            con[st.top()] = i; con[i] = st.top();
            st.pop();
        }
    }
    for (int i = 0; i <= n; i++) {
        l[i] = i - 1; r[i] = i + 1;
    }
    for (int i = 0; i < m; i++){
        cin >> ch;
        if (ch == 'L')
            it = l[it];
        else if (ch == 'R')
            it = r[it];
        else{
            if (it > con[it]) it = con[it];
            ll = l[it];
            rr = r[con[it]];
            r[ll] = rr;
            l[rr] = ll;
            it = rr;
            if (it == n + 1) it = ll;
        }
    }
    for (int i = r[0]; i <= n; i = r[i])
        cout << s[i - 1];
}


/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,p;
    cin >> n >> m >> p;
    string s;
    cin >> s;
    string t;
    cin >> t;
    p--;
    //cout << p;
    for(int i=0; i<m; i++) {
        if(t[i]=='L') p--;
        if(t[i]=='R') p++;
        if(t[i]=='D') {
            //cout << s[p] << " ";
            if(s[p]=='(') {
                int d=1;
                int t=1;
                for(int j=p+1; j<s.size(); j++) {
                    if(s[j]=='(') d++;
                    if(s[j]==')') d--;
                    t++;
                    if(d==0) {
                        break;
                    }
                }
                //cout << "a" << s[p];
                s.erase(p,t);
                cout << s << " ";
            }
            if(s[p]==')') {
                int d=1;
                int t=1;
                for(int j=p-1; j>=0; j--) {
                    if(s[j]=='(') d--;
                    if(s[j]==')') d++;
                    t++;
                    if(d==0) {
                        break;
                    }
                }
                //cout << t << " ";
                s.erase(p-t+1,t);

                //cout << p << " " << i <<endl;
                p-=t-1;
                while(p>=s.size()) p--;
            }
        }
    }
    cout << s;
    return 0;
}*/
