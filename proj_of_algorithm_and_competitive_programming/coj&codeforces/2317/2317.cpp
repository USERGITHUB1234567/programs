#include <iostream>
#include <string>

using namespace std;

bool canBePalindromeByOneChange(const string &s) {
    int n = s.length();
    int diffCount = 0;

    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            ++diffCount;
        }
    }

    return diffCount == 1 || (diffCount == 0 && n % 2 == 1);
}

int main() {
    string s;
    cin >> s;

    if (canBePalindromeByOneChange(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
