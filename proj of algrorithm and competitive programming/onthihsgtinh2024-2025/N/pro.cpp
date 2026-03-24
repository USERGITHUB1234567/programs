#include <iostream>
#include <string>
using namespace std;

int main() {
    // freopen("pr.inp", "r", stdin);
    // freopen("pr.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string s1 = "", s2 = "";
        char c;
        bool ck = false;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]) && !ck) {
                s1 += s[i];
            } else if (isdigit(s[i]) && ck) {
                s2 += s[i];
            } else if (s[i] == '=' || s[i] == '<' || s[i] == '>') {
                c = s[i];
                ck = true;
            }
        }

        long long a = stoll(s1), b = stoll(s2);
        if ((a < b && c == '<') || (a > b && c == '>') || (a == b && c == '=')) {
            cout << s << "\n";
        } else {
            cout << 0 << "<" << 1 << "\n";
        }
    }
    return 0;
}
