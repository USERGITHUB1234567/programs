/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
map<long long,long long>mp;
void pt(long long n)
{
    for(long long i=2; i*i<=n; i++) {
        if(n%i==0) {
            long long d=0;
            while(n%i==0) {
                n/=i;
                d++;
            }
            if(mp[i]==0) mp[i]=d;
            else mp[i]=min(mp[i],d);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    long long b[m];
    for(int i = 0; i < m; i++) cin >> b[i];

}*/
#include <iostream>
#include <vector>
#include <numeric> // Để sử dụng std::gcd
#include <iomanip> // Để sử dụng std::setfill và std::setw

using namespace std;

// Hàm tính GCD của danh sách số
long long gcd_list(const vector<int>& numbers) {
    return accumulate(numbers.begin(), numbers.end(), numbers[0], std::gcd<long long, long long>);
}

int main() {
    int N, M;

    // Đọc số lượng số trong tập hợp A
    cin >> N;
    vector<int> A_factors(N);
    for (int i = 0; i < N; i++) {
        cin >> A_factors[i];
    }

    // Đọc số lượng số trong tập hợp B
    cin >> M;
    vector<int> B_factors(M);
    for (int i = 0; i < M; i++) {
        cin >> B_factors[i];
    }

    // Tính GCD của các số trong tập hợp A và B
    long long gcd_A = gcd_list(A_factors);
    long long gcd_B = gcd_list(B_factors);

    // Tính GCD của A và B
    long long result = std::gcd(gcd_A, gcd_B);

    // Chỉ in ra 9 chữ số cuối cùng
    string result_str = to_string(result);
    if (result_str.size() > 9) {
        result_str = result_str.substr(result_str.size() - 9); // Lấy 9 chữ số cuối
    }

    // Bổ sung số 0 ở đầu nếu cần thiết
    cout << setfill('0') << setw(9) << result_str << endl;

    return 0;
}
