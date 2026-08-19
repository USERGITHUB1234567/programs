#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Sàng Eratosthenes để tìm tất cả các số nguyên tố <= n
vector<bool> sieve_of_eratosthenes(int n) {
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

// Hàm kiểm tra số siêu nguyên tố
bool is_super_prime(int prime, const vector<bool>& sieve) {
    string num_str = to_string(prime);
    if (num_str.find('0') != string::npos) {
        return false; // Không chứa chữ số 0
    }
    // Kiểm tra khi lần lượt bỏ các chữ số bên trái
    for (int i = 0; i < num_str.size(); ++i) {
        if (!sieve[stoi(num_str.substr(i))]) {
            return false; // Nếu không phải số nguyên tố khi bỏ chữ số đầu
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;

    vector<int> tests(t);
    int max_n = 0;
    for (int i = 0; i < t; ++i) {
        cin >> tests[i];
        max_n = max(max_n, tests[i]);
    }

    // Tạo sàng Eratosthenes đến số lớn nhất trong các test
    vector<bool> sieve = sieve_of_eratosthenes(max_n);

    // Tiền xử lý số lượng các số siêu nguyên tố cho đến max_n
    vector<int> super_prime_count(max_n + 1, 0);
    for (int i = 2; i <= max_n; ++i) {
        if (sieve[i] && is_super_prime(i, sieve)) {
            super_prime_count[i] = super_prime_count[i - 1] + 1;
        } else {
            super_prime_count[i] = super_prime_count[i - 1];
        }
    }

    // Xử lý từng test và in ra kết quả
    for (int i = 0; i < t; ++i) {
        cout << super_prime_count[tests[i]] << endl;
    }

    return 0;
}
