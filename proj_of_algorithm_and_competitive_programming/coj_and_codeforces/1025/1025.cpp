#include <iostream>
using namespace std;

int findComfortableCluster(int N, int K) {
    while (K > N) {
        int M = K % N;
        if (M == 0) {
            return N;
        }
        K = M + N;
        N = M;
    }
    return N;
}

int main() {
    int N, K;
    cin >> N >> K;

    int result = findComfortableCluster(N, K);
    cout << result << endl;

    return 0;
}
