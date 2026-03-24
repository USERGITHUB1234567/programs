#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    long long steps = 0;

    // Nếu k = 1 thì chỉ có thể trừ đi 1 ở mỗi bước.
    if(k == 1){
        cout << n << "\n";
        return 0;
    }

    while(n > 0){
        if(n % k == 0){
            // Nếu n chia hết cho k thì chia n cho k
            n /= k;
            steps++;
        } else {
            // Nếu không chia hết, trừ số cần thiết để đến được số chia hết cho k.
            long long r = n % k; // số dư khi chia n cho k
            // Nếu n < k thì r = n (không thể chia được nữa)
            n -= r;
            steps += r;
        }
    }

    cout << steps << "\n";
    return 0;
}
