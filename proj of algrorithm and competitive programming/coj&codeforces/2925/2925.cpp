#include <iostream>
using namespace std;

long long countTrailingZeros(long long n) {
    long long count = 0;
    for (long long i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    cout << countTrailingZeros(n) << endl;

    return 0;
}
