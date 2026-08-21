#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long a, b;
        cin >> a >> b;
        // Calculate the side length of the square
        long long side = max(2 * min(a, b), max(a, b));
        // Calculate and print the area of the square
        cout << side * side << "\n";
    }
}
