#include <iostream>
#include <string>
using namespace std;

string rotateString(const string &s, int d) {
    int L = s.length();
    int shift = d % L;
    return s.substr(shift) + s.substr(0, shift);
}

int main() {
    int d;
    cin >> d;
    string slogan = "CHAO_MUNG_CAC_THAY_CO_VA_CAC_EM.";
    cout << rotateString(slogan, d) << endl;
    return 0;
}
