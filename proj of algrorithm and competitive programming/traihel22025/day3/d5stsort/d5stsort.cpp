#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=300005;
stack<int>s1,s2;
int n,kq=0,cur=0;
bool mk[maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        s1.push(x);
    }
    while(cur!=n) {
        int tar=cur+1;
        if(!s1.empty() && s1.top()==tar) {
            s1.pop();
            cur++;
            kq++;
            continue;
        }
        else if(!s2.empty() && s2.top()==tar) {
            s2.pop();
            cur++;
            kq++;
            continue;
        }
        else {
            if(!mk[tar]) {
                while(s1.top()!=tar) {
                    s2.push(s1.top());
                    mk[s1.top()]=true;
                    s1.pop();
                    kq++;
                }
                s1.pop();
                cur++;
                kq++;
                continue;
            }
            else if(mk[tar]){
                while(s2.top()!=tar) {
                    s1.push(s2.top());
                    mk[s2.top()]=false;
                    s2.pop();
                    kq++;
                }
                s2.pop();
                cur++;
                kq++;
                continue;
            }
        }
    }
    cout << kq;
}