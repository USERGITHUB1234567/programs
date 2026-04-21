#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 INF64 = (int64)4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N)) return 0;
    vector<int64> A(N+1);
    for(int i=1;i<=N;i++) cin >> A[i];

    // L[i]: minimal possible B[i] when forcing strictly increasing from left to i
    vector<int64> L(N+1,0), R(N+2,0);
    L[1] = A[1];
    for(int i=2;i<=N;i++){
        L[i] = max(A[i], L[i-1] + 1);
    }
    R[N] = A[N];
    for(int i=N-1;i>=1;i--){
        R[i] = max(A[i], R[i+1] + 1);
    }

    int64 answer = INF64;

    // For each possible peak k
    vector<int64> B(N+1), C(N+1);
    for(int k=1;k<=N;k++){
        // minimal feasible peak height
        int64 H = max(L[k], R[k]);

        // build B with B[k]=H, then extend left and right choosing minimal values >= A[i]
        B[k] = H;
        // go left
        bool ok = true;
        for(int i=k-1;i>=1;i--){
            // must have B[i] < B[i+1], and B[i] >= A[i]
            int64 val = B[i+1] - 1; // upper bound to keep strict increase
            if(val < A[i]) { ok = false; break; } // infeasible with this H
            B[i] = max<int64>(A[i], min<int64>(val, INF64));
        }
        if(!ok) continue;
        // go right
        for(int i=k+1;i<=N;i++){
            int64 val = B[i-1] - 1; // must be < previous
            if(val < A[i]) { ok = false; break; }
            B[i] = max<int64>(A[i], min<int64>(val, INF64));
        }
        if(!ok) continue;

        // compute C and ops
        for(int i=1;i<=N;i++) C[i] = B[i] - A[i];
        int64 ops = 0;
        int64 prev = 0;
        for(int i=1;i<=N;i++){
            if(C[i] > prev) ops += (C[i] - prev);
            prev = C[i];
        }
        answer = min(answer, ops);
    }

    if(answer==INF64) answer = 0; // fallback (shouldn't happen)
    cout << answer << '\n';
    return 0;
}
