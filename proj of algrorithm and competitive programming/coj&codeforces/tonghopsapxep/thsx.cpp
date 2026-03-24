#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;

const int MAX_SIZE = 1e6 + 1;
ll a[MAX_SIZE];

void inter_sort(int g, int n)
{
    for(int i = g; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[j] > a[i]) swap(a[i], a[j]);
        }
    }
}

void bubble_sort(int g, int n)
{
    for(int i = g; i < n; i++) {
        for(int j = n; j > i; j--) {
            if(a[j] < a[j - 1]) swap(a[j], a[j - 1]);
        }
    }
}

void insert_sort(int g, int n)
{
    for(int i = g + 1; i <= n; i++) {
        ll key = a[i];
        int j = i - 1;
        while(j >= g && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void selec_sort(int g, int n)
{
    for(int i = g; i < n; i++) {
        int min_index = i;
        for(int j = i + 1; j <= n; j++) {
            if(a[j] < a[min_index]) min_index = j;
        }
        swap(a[i], a[min_index]);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    bubble_sort(0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
