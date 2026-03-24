#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < n; ++i) {
        int mini, maxi;
        if (i == 0) {
            mini = abs(x[i] - x[i + 1]);
            maxi = abs(x[i] - x[n - 1]);
        } else if (i == n - 1) {
            mini = abs(x[i] - x[i - 1]);
            maxi = abs(x[i] - x[0]);
        } else {
            mini = min(abs(x[i] - x[i - 1]), abs(x[i] - x[i + 1]));
            maxi = max(abs(x[i] - x[0]), abs(x[i] - x[n - 1]));
        }
        cout << mini << " " << maxi << endl;
    }

    return 0;
}
