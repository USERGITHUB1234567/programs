#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<string> kq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        string t = "";
        for (int i = 0; i < s.size(); i++){
            if(isdigit(s[i])) t += s[i];
            else{
                if(!t.empty()){
                    while(t.size() > 1 && t[0] == '0') t.erase(t.begin());
                    if(t != "") kq.push_back(t);
                    t = "";
                }
            }
        }
        if(!t.empty()){
            while(t.size() > 1 && t[0] == '0') t.erase(t.begin());
            kq.push_back(t);
        }
    }
    sort(kq.begin(), kq.end(), [](const string &a, const string &b){
        if(a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });
    for(auto t : kq) cout << t << "\n";
    return 0;
}
