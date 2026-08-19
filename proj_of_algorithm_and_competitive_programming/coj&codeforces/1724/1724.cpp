#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

bool legit(string s, string w) {
    long long it_w = 0, sus_cnt = 0;
    for (long long it_s = 0; it_s < s.size(); ++it_s) {
        if (s[it_s] != w[it_w]) {
            if (sus_cnt == 0) {
                sus_cnt++;
                it_s--; // thử lại cùng vị trí của s với ký tự kế tiếp của w
            } else {
                return false;
            }
        }
        it_w++;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    string u, no = "NOT POSSIBLE", uni = "NOT UNIQUE";
    cin >> n >> u;

    if (n % 2 == 0) {
        cout << no;
        return 0;
    }

    set<string> st;
    string s1 = u.substr(0, (n - 1) / 2);
    string test1 = u.substr((n - 1) / 2);
    string test2 = u.substr(0, (n - 1) / 2 + 1);
    string s2 = u.substr((n - 1) / 2 + 1);

    bool res1 = legit(s1, test1);
    if (res1)
        st.insert(s1);
    bool res2 = legit(s2, test2);
    if (res2)
        st.insert(s2);

    if (st.empty())
        cout << no << "\n";
    else if (st.size() > 1)
        cout << uni << "\n";
    else
        cout << *st.begin() << "\n";

    return 0;
}
