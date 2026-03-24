#include <iostream>
using namespace std;

long long countDigits(long long n) {
    long long count = 0;
    long long length = 1;
    long long base = 9;

    while (n > 0) {
        if (n >= base) {
            count += length * base;
            n -= base;
        } else {
            count += length * n;
            n = 0;
        }
        length++;
        base *= 10;
    }
    return count;
}

int main() {
    long long n;
    cin >> n;
    cout << countDigits(n) << endl;
    return 0;
}
