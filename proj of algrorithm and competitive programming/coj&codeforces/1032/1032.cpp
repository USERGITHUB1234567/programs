#include <iostream>
using namespace std;

int min_bags(int n) {
    for (int i = n / 5; i >= 0; i--) {
        if ((n - 5 * i) % 3 == 0) {
            return i + (n - 5 * i) / 3;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    cout << min_bags(n) << endl;
    return 0;
}
