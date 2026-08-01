#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first!=b.first) return a.first<b.first;
    else return a.second>b.second;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj_matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < n; ++j) {
                adj_matrix[i][j] = row[j] - '0';
            }
        }

        vector<pair<int, int>> edge_count(n);
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (adj_matrix[i][j] == 1) {
                    count++;
                }
            }
            edge_count[i] = {count, i + 1};
        }

        sort(edge_count.begin(), edge_count.end(),cmp);

        vector<int> permutation(n);
        for (int i = 0; i < n; ++i) {
            permutation[i] = edge_count[i].second;
        }

        for (int i = 0; i < n; ++i) {
            cout << permutation[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
