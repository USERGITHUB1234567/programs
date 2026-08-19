#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int minJumps(int n, int d, string s) {
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 1; i <= d; i++) {
            int next = curr + i;
            if (next < n && s[next] == '1' && dist[next] > dist[curr] + 1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    return (dist[n-1] == INT_MAX) ? -1 : dist[n-1];
}

int main() {
    int n, d;
    string s;
    cin >> n >> d >> s;

    int result = minJumps(n, d, s);
    cout << result;

    return 0;
}
