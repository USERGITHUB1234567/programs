#include <iostream>
#include <string>
using namespace std;

int main() {
    long long a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;

    long long score = 0;
    for (char c : s) {
        score += a[c - '1'];
    }

    cout << score << endl;
    return 0;
}
