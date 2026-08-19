#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const long long MAXN = 1e6 + 8;
bool isPrime[MAXN];

// Hàm dùng để tạo danh sách các số nguyên tố từ 2 đến MAXN bằng Sàng Eratosthenes
void generatePrimes() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false; // 0 và 1 không phải là số nguyên tố
    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                isPrime[j] = false; // Đánh dấu các bội số của i là không phải số nguyên tố
            }
        }
    }
}

// Hàm tính tổng các ước của một số n
long long sumOfDivisors(long long n) {
    long long sum = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i; // Nếu i không phải là căn bậc hai của n thì cộng thêm n / i
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    generatePrimes(); // Tạo danh sách các số nguyên tố
    long long n, result = 1;
    cin >> n;

    // Duyệt qua các số i từ 2 đến sqrt(n) để tính i^2 và kiểm tra nếu tổng ước của i^2 là số nguyên tố
    for (int i = 2; i * i <= n; i++) {
        long long t = i * i;
        if (isPrime[sumOfDivisors(t)]) { // Nếu tổng các ước của i^2 là số nguyên tố
            result++;
        }
    }

    cout << result; // In kết quả
    return 0;
}
