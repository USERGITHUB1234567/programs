#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

long long countMultiples(long long K, long long num) {
    return K / num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long K;
    cin >> K;

    long long low = 1, high = 1e18, result = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long count = countMultiples(mid, 3) + countMultiples(mid, 5) + countMultiples(mid, 7)
                        - countMultiples(mid, 15) - countMultiples(mid, 21) - countMultiples(mid, 35)
                        + countMultiples(mid, 105);

        if (count >= K) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result;
    return 0;
}
