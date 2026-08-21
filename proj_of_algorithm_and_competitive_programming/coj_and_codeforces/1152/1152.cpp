#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int e(const string& x) {
    int r = 0, c = 0;
    char s = '+';
    for (int i = 0; i < x.size(); i++) {
        if (isdigit(x[i])) {
            c = c * 10 + (x[i] - '0');
        } else {
            if (s == '+') r += c;
            else r -= c;
            c = 0;
            s = x[i];
        }
    }
    if (s == '+') r += c;
    else r -= c;
    return r;
}
void b(const string& x, int i, string y, int m, vector<string>& z) {
    if (i == x.size()) {
        if (e(y) == m) z.push_back(y);
        return;
    }
    b(x, i + 1, y + "+" + x[i], m, z);
    b(x, i + 1, y + "-" + x[i], m, z);
    b(x, i + 1, y + x[i], m, z);
}
int main() {
    string x = "123456789";
    int m;
    cin >> m;
    vector<string> z;
    b(x, 1, string(1, x[0]), m, z);
    b(x, 1, "-" + string(1, x[0]), m, z);
    if (z.empty()) cout << "vo nghiem";
    else for (int i = 0; i < z.size(); i++) cout << z[i] << "\n";
    return 0;
}
