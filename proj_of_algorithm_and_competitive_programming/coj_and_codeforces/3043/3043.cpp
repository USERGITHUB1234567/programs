#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    vector<pair<int,int>> queries(Q);
    int max_R = 0;

    // Đọc các truy vấn và xác định giá trị R_max
    for(int i = 0; i < Q; i++){
        int L, R;
        cin >> L >> R;
        queries[i] = {L, R};
        max_R = max(max_R, R);
    }

    // Tính tổng các ước của mỗi số (không kể số đó)
    vector<int> sumDiv(max_R + 1, 0);
    for (int i = 1; i <= max_R; i++){
        for (int j = 2 * i; j <= max_R; j += i){
            sumDiv[j] += i;
        }
    }

    // Xác định số dồi dào (n là số dồi dào nếu n <= sumDiv[n])
    vector<int> doiDao(max_R + 1, 0);
    for (int n = 1; n <= max_R; n++){
        if(n <= sumDiv[n])
            doiDao[n] = 1;
    }

    // Xây dựng mảng tiền tố để truy vấn nhanh
    vector<int> prefix(max_R + 1, 0);
    for (int n = 1; n <= max_R; n++){
        prefix[n] = prefix[n - 1] + doiDao[n];
    }

    // Xử lý các truy vấn và in kết quả
    for(auto &q : queries){
        int L = q.first, R = q.second;
        cout << prefix[R] - (L - 1 >= 0 ? prefix[L - 1] : 0) << "\n";
    }

    return 0;
}
