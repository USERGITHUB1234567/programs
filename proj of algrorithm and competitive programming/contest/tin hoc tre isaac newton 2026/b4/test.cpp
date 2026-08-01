#include <bits/stdc++.h>
using namespace std;

/*
  Đọc:
    - Dòng đầu: c (số màu)
    - Các dòng tiếp: các cặp (w, color) cho đến EOF
  Xuất:
    - Một dòng chứa các chỉ số (1-based) của các viên sỏi được chọn vào tập 1,
      cách nhau bởi dấu cách. (Nếu có nhiều đáp án tối ưu, in một đáp án bất kỳ.)
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c;
    if(!(cin >> c)) return 0;
    vector<pair<int,int>> stones; // (weight, color)
    int w, col;
    while(cin >> w >> col){
        stones.emplace_back(w, col);
    }
    int N = (int)stones.size();
    if(N == 0) return 0;
    if(N % c != 0){
        // không hợp lệ theo đề, nhưng thoát an toàn
        return 0;
    }
    int t = N / c;
    if(t % 2 != 0){
        // nếu t lẻ thì không thể chia đều theo nửa; theo đề t phải chẵn
        // in rỗng hoặc xử lý tùy ý; ở đây ta dừng.
        return 0;
    }
    int need = t/2;

    // Gom chỉ số theo màu (mã màu có thể không bắt đầu từ 1 liên tiếp)
    // Ta sẽ map mã màu về 0..c-1
    unordered_map<int,int> colorMap;
    int idxColor = 0;
    for(auto &p: stones){
        int cc = p.second;
        if(colorMap.find(cc) == colorMap.end()){
            colorMap[cc] = idxColor++;
        }
    }
    // nếu số màu thực tế khác c, vẫn xử lý theo màuMap.size()
    int C = idxColor;
    vector<vector<pair<int,int>>> byColor(C); // (weight, original_index)
    for(int i=0;i<N;i++){
        int cc = colorMap[stones[i].second];
        byColor[cc].push_back({stones[i].first, i+1}); // lưu chỉ số 1-based
    }

    long long total = 0;
    for(auto &p: stones) total += p.first;

    // Với mỗi màu, liệt kê tất cả tổng khi chọn need viên, và lưu một tổ hợp chỉ số tương ứng
    vector<unordered_map<int, vector<int>>> sumsPerColor(C);
    for(int i=0;i<C;i++){
        int m = (int)byColor[i].size();
        // generate all combinations of size need
        // nếu m == need thì chỉ có một tổ hợp
        if(m == need){
            int s = 0;
            vector<int> idxs;
            for(auto &pr: byColor[i]){
                s += pr.first;
                idxs.push_back(pr.second);
            }
            sumsPerColor[i][s] = idxs;
            continue;
        }
        // nếu m nhỏ, dùng tổ hợp bằng bitmask
        // iterate bitmask of length m with exactly need bits
        // nếu m <= 30, có thể dùng bitmask; nếu m lớn, dùng sinh tổ hợp kết hợp
        vector<int> choose;
        function<void(int,int,int,int)> gen = [&](int pos, int taken, int curSum, int dummy){
            if(taken == need){
                // lưu chỉ một tổ hợp cho tổng curSum nếu chưa có
                if(sumsPerColor[i].find(curSum) == sumsPerColor[i].end()){
                    sumsPerColor[i][curSum] = choose;
                }
                return;
            }
            if(pos == m) return;
            // prune: còn lại m-pos, cần need-taken
            if(m - pos < need - taken) return;
            // chọn pos
            choose.push_back(byColor[i][pos].second);
            gen(pos+1, taken+1, curSum + byColor[i][pos].first, 0);
            choose.pop_back();
            // không chọn pos
            gen(pos+1, taken, curSum, 0);
        };
        gen(0,0,0,0);
    }

    // DP theo màu: dp_sums là tập các tổng khả dĩ sau khi xử lý k màu
    // parent[k][sum] = previous sum trước khi thêm màu k (k từ 0..C-1)
    // choiceSum[k][sum] = tổng do màu k đóng góp (để truy vết)
    vector<unordered_map<int,int>> parent(C);
    vector<unordered_map<int,int>> choiceSum(C);

    // khởi tạo với màu 0
    bool first = true;
    unordered_set<int> curSums;
    if(C == 0) return 0;
    for(auto &kv: sumsPerColor[0]){
        int s = kv.first;
        curSums.insert(s);
        parent[0][s] = -1; // không có tiền nhiệm
        choiceSum[0][s] = s;
    }

    // lặp các màu tiếp theo
    for(int k=1;k<C;k++){
        unordered_set<int> nextSums;
        for(int prevSum: curSums){
            for(auto &kv: sumsPerColor[k]){
                int add = kv.first;
                int ns = prevSum + add;
                if(nextSums.find(ns) == nextSums.end()){
                    nextSums.insert(ns);
                    parent[k][ns] = prevSum;
                    choiceSum[k][ns] = add;
                }
            }
        }
        curSums.swap(nextSums);
    }

    // tìm tổng S sao cho |T - 2S| nhỏ nhất
    long long bestDiff = LLONG_MAX;
    int bestS = -1;
    for(int s: curSums){
        long long diff = llabs(total - 2LL * s);
        if(diff < bestDiff){
            bestDiff = diff;
            bestS = s;
        }
    }

    // truy vết các tổng đóng góp từng màu
    vector<int> chosenSumPerColor(C, 0);
    int cur = bestS;
    for(int k = C-1; k>=0; --k){
        int add = choiceSum[k][cur];
        chosenSumPerColor[k] = add;
        int prev = parent[k][cur];
        cur = prev;
    }

    // từ chosenSumPerColor lấy chỉ số viên sỏi
    vector<int> result;
    for(int k=0;k<C;k++){
        int s = chosenSumPerColor[k];
        auto it = sumsPerColor[k].find(s);
        if(it != sumsPerColor[k].end()){
            for(int id: it->second) result.push_back(id);
        } else {
            // không tìm thấy (không nên xảy ra)
        }
    }

    // In kết quả: các chỉ số (không cần theo thứ tự đặc biệt)
    for(size_t i=0;i<result.size();++i){
        if(i) cout << ' ';
        cout << result[i];
    }
    cout << '\n';
    return 0;
}
