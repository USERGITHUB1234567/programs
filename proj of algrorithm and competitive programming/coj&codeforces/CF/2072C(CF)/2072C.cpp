/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int btd(string s)
{
    int k=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='1') {
            k*=2;
            k++;
        }
        else k*=2;
    }
    return k;
}
string dtb(int k)
{
    string s="";
    while(k>0) {
        if(k%2==1) {
            s+='1';
            k/=2;
        }
        else {
            s+='0';
            k/=2;
        }
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string c="1";
    for(int i=1; i<=10; i++) c+=c;
    int t;
    cin >> t;
    while(t--) {
        int n,x;
        cin >> n >> x;
        string q=dtb(x);
        int a=btd(q);
        int vt=0;
        for(int i=q.size()-1; i>=0; i--) {
            if(q[i]=='1') vt++;
            else break;
        }
        string s=c.substr(0,vt);
        int b=btd(s);
        vector<int>kq;
        int i=0,k=i;
        for(i; i<min(n-1,b); i++) {
            kq.push_back(i);
            k=k|i;
        }
        k=k|i+1;
        if(k==x)
            a=x;
        for(i; i<n; i++) {
            kq.push_back(a);
        }
        for(int j:kq) cout << j << " ";
        cout << "\n";
    }
}*/
#include <bits/stdc++.h>
using namespace std;

// Explanation:
// - We first compute the largest p such that the lower p bits of x are all 1;
//   i.e. (x & ((1<<p)-1)) == ((1<<p)-1). Then the ideal prefix would be all numbers in [0, (1<<p)-1].
// - If n is large enough we try to include that full prefix. If x is larger than (1<<p)-1 then we need to include
//   an extra element to cover the extra bits of x.
// - If n is too small to include the full prefix, we start with [0,1,…,n-1] and if their OR isn’t x, we replace
//   the largest element with one that “adds” the missing bits.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;

        vector<int> ans;
        // Special case: if x == 0, then the only allowed number is 0.
        if(x == 0){
            for(int i = 0; i < n; i++){
                cout << 0 << " ";
            }
            cout << "\n";
            continue;
        }

        // Determine the maximum p such that the lower p bits of x are set.
        int p = 0;
        for (int bit = 0; bit < 31; bit++){
            int mask = (1 << (bit+1)) - 1; // numbers 0 ... (2^(bit+1)-1)
            if((mask & (~x)) == 0){ // all bits in mask appear in x
                p = bit + 1;
            } else {
                break;
            }
        }
        int m0 = 1 << p; // ideal prefix: 0,1,..., m0-1 would give MEX = m0 if included

        // Case 1: When n is at least m0.
        if(n >= m0){
            if(x == m0 - 1){
                // Allowed numbers are exactly the prefix.
                for(int i = 0; i < m0; i++){
                    ans.push_back(i);
                }
                // Fill extra slots with 0.
                while((int)ans.size() < n){
                    ans.push_back(0);
                }
            } else {
                // x has extra bits.
                if(n > m0){
                    // We can include the whole prefix and then add x.
                    for(int i = 0; i < m0; i++){
                        ans.push_back(i);
                    }
                    ans.push_back(x);
                    while((int)ans.size() < n)
                        ans.push_back(0);
                } else { // n == m0, so we must sacrifice one element.
                    for(int i = 0; i < m0 - 1; i++){
                        ans.push_back(i);
                    }
                    ans.push_back(x);
                }
            }
        } else {
            // Case 2: n < m0.
            int or_val = 0;
            for(int i = 0; i < n; i++){
                or_val |= i;
            }
            if(or_val == x){
                for(int i = 0; i < n; i++){
                    ans.push_back(i);
                }
            } else {
                int missing = x & (~or_val); // bits in x missing from the OR of 0...n-1
                int candidate = (n - 1) | missing;
                for(int i = 0; i < n - 1; i++){
                    ans.push_back(i);
                }
                ans.push_back(candidate);
            }
        }

        for(auto v : ans)
            cout << v << " ";
        cout << "\n";
    }
    return 0;
}

