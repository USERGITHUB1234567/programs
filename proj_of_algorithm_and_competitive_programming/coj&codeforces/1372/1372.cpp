#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        degree[xi]++;
        degree[yi]++;
    }

    bool isBus = (m == n - 1);
    bool isRing = (m == n);
    bool isStar = (m == n - 1);

    int countOne = 0, countTwo = 0, countCenter = 0;

    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) countOne++;
        else if (degree[i] == 2) countTwo++;
        else if (degree[i] == n - 1) countCenter++;
    }

    if (isBus && countOne == 2 && countTwo == n - 2) {
        cout << "bus topology" << endl;
    } else if (isRing && countTwo == n) {
        cout << "ring topology" << endl;
    } else if (isStar && countCenter == 1 && countOne == n - 1) {
        cout << "star topology" << endl;
    } else {
        cout << "unknown topology" << endl;
    }

    return 0;
}
