#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long INF = 1e9;

long long d[102][102];
bool nc[102][102];
map<int, string> name;
int n;

void floydwarshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INF && d[k][j] != INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void checkNegativeCycles() {
    for (int k = 1; k <= n; k++) {
        if (d[k][k] < 0) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (d[i][k] != INF && d[k][j] != INF)
                        nc[i][j] = true;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Khởi tạo mảng nc và khoảng cách
    memset(nc, false, sizeof(nc));
    for (int i = 1; i < 102; i++){
        for (int j = 1; j < 102; j++){
            d[i][j] = INF;
        }
    }

    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        name[i] = s;
        for (int j = 1; j <= n; j++){
            long long w;
            cin >> w;
            d[i][j] = min(d[i][j], w);
        }
        if(d[i][i] > 0)
            d[i][i] = 0;
    }
    floydwarshall();
    checkNegativeCycles();
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        if(nc[u][v]){
            cout << "NEGATIVE CYCLE\n";
        }
        else if(d[u][v] == INF){
            cout << name[u] << "-" << name[v] << " NOT REACHABLE\n";
        }
        else {
            cout << name[u] << "-" << name[v] << " " << d[u][v] << "\n";
        }
    }

    return 0;
}
