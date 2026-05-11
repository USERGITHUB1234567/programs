#include <iostream>
#include <vector>

using namespace std;

vector<long long> fib_length(46);

void precompute_fib_length() {
    fib_length[0] = 1; // F0 = "a"
    fib_length[1] = 1; // F1 = "b"
    for (int i = 2; i <= 45; ++i) {
        fib_length[i] = fib_length[i - 2] + fib_length[i - 1];
    }
}

char find_kth_character(int n, long long k) {
    if (n == 0) return 'a';
    if (n == 1) return 'b';
    if (k <= fib_length[n - 2]) {
        return find_kth_character(n - 2, k);
    } else {
        return find_kth_character(n - 1, k - fib_length[n - 2]);
    }
}

int main() {
    precompute_fib_length();
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long k;
        cin >> n >> k;
        cout << find_kth_character(n, k) << endl;
    }
    return 0;
}
