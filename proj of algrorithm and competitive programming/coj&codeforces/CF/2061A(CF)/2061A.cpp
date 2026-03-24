#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int cal(vector<long long>& a) {
    vector<long long> even_numbers, odd_numbers;
    for (long long num : a) {
        if (num % 2 == 0) {
            even_numbers.push_back(num);
        } else {
            odd_numbers.push_back(num);
        }
    }

    long long s = 0, points = 0;
    for (long long num : even_numbers) {
        s += num;
        if (s % 2 == 0) {
            points++;
            while (s % 2 == 0) {
                s /= 2;
            }
        }
    }
    for (long long num : odd_numbers) {
        s += num;
        if (s % 2 == 0) {
            points++;
            while (s % 2 == 0) {
                s /= 2;
            }
        }
    }
    return points;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,kq=0,lc=0,t=0;
        cin >> n;
        vector<long long> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];

        }
        cout << cal(a) << "\n";
    }
}
