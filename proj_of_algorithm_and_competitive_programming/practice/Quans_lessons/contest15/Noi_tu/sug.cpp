#include <bits/stdc++.h>
using namespace std;
const int maxn=100005,maxt=1000006;
vector<vector<vector<string>>>test_case;
int tc,n_case[maxt];

namespace appetizersoup{
    vector<int>adj[maxn];
    map<string,vector<int>>ending;
    int out[maxn];
    int orig_out[maxn]; // Cần mảng này để lưu lại bậc ra ban đầu của các từ
    short state[maxn];

    void bfs(int n) {
        queue<int>q;
        for(int i=0; i<n; ++i) {
            if(!out[i]) {
                state[i]=-1; // Không có đường ra -> THUA (-1)
                q.push(i);
            }
        }
        while(!q.empty()) {
            int u=q.front(); q.pop();
            for(int v:adj[u]) {
                if(!state[v]) {
                    if(state[u]==-1) { // Nếu u là Thua -> v đi vào u sẽ là Thắng (1)
                        state[v]=1;
                        q.push(v);
                    }
                    else if(state[u]==1) { // Nếu u là Thắng -> v mất 1 đường đi
                        --out[v];
                        if(out[v]==0) { // Nếu tất cả các đường từ v đều dẫn đến Thắng của đối thủ
                            state[v]=-1; // Thì v mới là Thua (-1)
                            q.push(v);
                        }
                    }
                }
            }
        }
    }

    void implement() {
        // Fix 1: Duyệt t từ 0 đến tc-1 vì test_case trong main push_back từ 0
        for(int t=0; t<tc; ++t) {
            int n=n_case[t];
            
            // Fix 2: Phải clear dữ liệu cũ sau mỗi bộ test
            ending.clear();
            for(int i=0; i<n; ++i) {
                out[i]=0;
                state[i]=0;
                adj[i].clear();
            }

            for(int i=0; i<n; ++i) {
                string t2=test_case[t][i][1];
                ending[t2].push_back(i);
            }

            for(int i=0; i<n; ++i) {
                string t1=test_case[t][i][0];
                for(int j:ending[t1]) {
                    // Từ j nối vào từ i -> đồ thị cạnh ngược (vào adj[i] là j)
                    ++out[j];
                    adj[i].push_back(j);
                }
            }

            // Lưu lại bậc ra ban đầu (trước khi bị BFS thay đổi)
            for(int i=0; i<n; ++i) {
                orig_out[i] = out[i];
            }

            bfs(n);

            // Fix 4: Kiểm tra xem Quang có thể chọn từ nào để đi đầu tiên không
            bool can_win = false, can_draw = false;
            for(int i=0; i<n; ++i) {
                // Từ xuất phát phải có đường đi tiếp (orig_out > 0)
                if(orig_out[i] > 0) {
                    if(state[i] == -1) can_win = true; // Ép đối thủ (Hiếu) vào thế Thua -> Quang Thắng
                    else if(state[i] == 0) can_draw = true; // Câu hoà
                }
            }

            if(can_win) cout << "Quang";
            else if(can_draw) cout << "Hoa";
            else cout << "Hieu";
            cout << '\n';
        }
    }
}

int main(int argc, char** argv) {
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(cin >> tc) {
        test_case.reserve(tc);
        for(int i=0; i<tc; ++i) {
            cin >> n_case[i];
            vector<vector<string>>tmp;
            tmp.reserve(n_case[i]);
            for(int j=1; j<=n_case[i]; ++j) {
                string t1,t2; 
                cin >> t1 >> t2;
                tmp.push_back({t1,t2});
            }
            test_case.push_back(tmp);
        }
        appetizersoup::implement();
    }
    return 0;
}