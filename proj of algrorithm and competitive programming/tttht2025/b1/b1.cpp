#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int k,l=2;
vector<long long>kq;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> k;
    while(kq.size()<k) {
        vector<char>t;
        for(int i=0; i<l; i++) {
            if(i==0) t={'1','2','3','4','6','7','8','9'};
            else t={'0','1','2','3','4','6','7','8','9'};
            for(char c:t) {
                string s="";
                for(int j=1; j<=l; j++) s+='5';
                s[i]=c;
                kq.push_back(stoll(s));
            }
        }
        l++;
    }
    sort(kq.begin(),kq.end());
    cout << kq[k-1];
}
