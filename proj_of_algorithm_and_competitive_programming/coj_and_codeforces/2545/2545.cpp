#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef long long ll;

// Hàm tạo mảng các số nguyên tố đến n sử dụng Sieve of Eratosthenes.
vector<int> getPrimes(int n) {
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i)
                sieve[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (sieve[i])
            primes.push_back(i);
    }
    return primes;
}

// Hàm chuyển đổi số x thành dạng "square-free".
ll squareFree(ll x, const vector<int>& primes) {
    ll res = 1;
    for (auto p : primes) {
        if ((ll)p * p > x) break;
        int count = 0;
        while (x % p == 0) {
            count++;
            x /= p;
        }
        // Nếu số lần chia ra số nguyên tố p là lẻ, nhân p vào kết quả.
        if (count % 2 == 1) {
            res *= p;
        }
    }
    // Nếu sau khi chia hết các số nguyên tố nhỏ, x > 1 thì x là số nguyên tố (với số mũ 1)
    if (x > 1) {
        res *= x;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Tìm giá trị lớn nhất để xác định giới hạn cho số nguyên tố
    int max_val = 0;
    for(auto v : arr) {
        max_val = max(max_val, (int)v);
    }
    int limit = sqrt(max_val) + 1;
    vector<int> primes = getPrimes(limit);

    // Chuyển các phần tử của mảng sang dạng "square-free"
    vector<ll> transformed(n);
    for (int i = 0; i < n; i++){
        transformed[i] = squareFree(arr[i], primes);
    }

    // Sử dụng phương pháp tham tham để chia mảng thành các đoạn liên tiếp
    int segments = 1;
    unordered_set<ll> seen;
    for (int i = 0; i < n; i++){
        // Nếu giá trị transformed[i] đã tồn tại trong tập seen, bắt đầu đoạn mới
        if (seen.find(transformed[i]) != seen.end()){
            segments++;
            seen.clear();
        }
        seen.insert(transformed[i]);
    }
    cout << segments << "\n";
    return 0;
}
