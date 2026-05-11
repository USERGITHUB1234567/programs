#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // Number of piles
    cin >> n;
    vector<int> piles(n); // Array to store the size of each pile

    // Input the piles
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    // Step 1: Compute the Nim-sum
    int nim_sum = 0;
    for (int i = 0; i < n; i++) {
        nim_sum ^= piles[i];
    }

    // Step 2: Determine the result
    if (nim_sum == 0) {
        // If Nim-sum is 0, player 1 will lose
        cout << "Lose" << endl;
    } else {
        // If Nim-sum is non-zero, player 1 can win
        cout << "Win" << endl;
        for (int i = 0; i < n; i++) {
            // Step 3: Find the pile to make the Nim-sum zero
            int target = piles[i] ^ nim_sum;
            if (target < piles[i]) {
                cout << i + 1 << " " << piles[i] - target;
                break;
            }
        }
    }

    return 0;
}
