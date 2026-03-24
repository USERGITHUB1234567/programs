#include <iostream>
#include <string>
using namespace std;

long long countEvenSubstrings(const string& s) {
    int n = s.length();
    long long count = 0;

    for (int i = 0; i < n; ++i) {
        if ((s[i] - '0') % 2 == 0) {
            count += (i + 1);
        }
    }

    return count;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    cout << countEvenSubstrings(s) << endl;

    return 0;
}
