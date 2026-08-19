#include <bits/stdc++.h>
#include <cassert>
using namespace std;

vector<int> solveGenius(int N, int S, const vector<int>& U, const vector<int>& V);
bool solveCitizen(const vector<int>& A,const vector<vector<int>>& history);

int main() {
	int N, K, S;
	cin >> N >> K >> S;

	vector<int> U, V;
	vector<int> inDeg(N, 0);
	vector<vector<int>> adj(N);

	for (int i = 0; i < K; ++i) {
		int u, v; cin >> u >> v;
		U.push_back(u);
		V.push_back(v);
		adj[u].push_back(v);
		++inDeg[v];
	}

	vector<int> X = solveGenius(N, S, U, V);
	assert(X.size() == N);
	for (int i = 0; i < N; ++i) assert(X[i] > 0);

	vector<vector<int>> history;
	vector<int> out(N, false);
	int cntOut = 0;

	for (int turn = 1; turn <= N; ++turn) {
		vector<int> currentTurn, vertex;
		for (int i = 0; i < N; ++i) {
			if (out[i]) continue;
			vector<int> A = X;
			A.erase(A.begin() + i);
			sort (A.begin(), A.end());
			bool leave = solveCitizen(A, history);
			if (leave) {
				out[i] = true;
				vertex.emplace_back(i);
				currentTurn.push_back(X[i]);
			}
		}
		assert(currentTurn.size() <= S);
		for (auto x : vertex) assert(inDeg[x] == 0);
		for (auto x : vertex)
			for (auto v : adj[x]) --inDeg[v];
		cntOut += currentTurn.size();
		sort (currentTurn.begin(), currentTurn.end());
		history.push_back(currentTurn);
	}

	assert(cntOut == N);

	int P = *max_element(X.begin(), X.end());
	cout << P << endl;

	return 0;
}