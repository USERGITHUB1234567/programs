#include <bits/stdc++.h>
using namespace std;
vector<int> tinh(const vector<int>& B, int n) {
    vector<int> A(n);
    A[0] = B[0];

    for (int i = 1; i < n; ++i) {
        A[i] = B[i] * (i + 1);
        for (int j = 0; j < i; ++j) {
            A[i] -= A[j];
        }
    }

    return A;
}
int main()
{
    long long n,t=0,d=1;
    cin >> n;
    vector<int>a;
    for(long long i=0; i<n; i++) {
        long long n;
        cin >> n;
        a.push_back(n);
    }
    vector<int>v=tinh(a,n);
    for(long long i=0; i<v.size()-1; i++) cout << v[i] << " ";
    cout << v[v.size()-1];
}

