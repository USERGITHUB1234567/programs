#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    set<string> B, C;

    // Tạo tập B có số phần tử nhỏ nhất
    for (int i = 0; i < n; i++) {
        string s = A[i];
        for (char &c : s) {
            if (c == '*') c = '0';
        }
        B.insert(s);
    }

    // Tạo tập C có số phần tử lớn nhất
    for (int i = 0; i < n; i++) {
        string s = A[i];
        for (char &c : s) {
            if (c == '*') c = '1';
        }
        C.insert(s);
    }

    cout << B.size() << endl;
    cout << C.size() << endl;

    return 0;
}
