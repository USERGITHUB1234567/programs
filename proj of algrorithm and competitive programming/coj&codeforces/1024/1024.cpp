#include <iostream>
#include <vector>
using namespace std;

int countWays(int x) {
    vector<vector<int>> dp(x + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= x; ++i) {
        for (int j = i; j <= x; ++j) {
            for (int k = j; k <= x; ++k) {
                for (int l = k; l <= x; ++l) {
                    if (i + j + k + l <= x) {
                        dp[j][k] += dp[i][j];
                    }
                }
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= x; ++i) {
        for (int j = i; j <= x; ++j) {
            for (int k = j; k <= x; ++k) {
                for (int l = k; l <= x; ++l) {
                    if (i + j + k + l == x) {
                        count += dp[j][k];
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    int x;
    cin >> x;
    cout << countWays(x) << endl;
    return 0;
}
