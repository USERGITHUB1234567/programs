#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int longestSubarrayWithDifference(vector<int>& arr, int k) {
    int n = arr.size();
    deque<int> maxDeque, minDeque;
    int left = 0, right = 0;
    int maxLength = 0;

    while (right < n) {
        while (!maxDeque.empty() && arr[maxDeque.back()] <= arr[right]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);

        while (!minDeque.empty() && arr[minDeque.back()] >= arr[right]) {
            minDeque.pop_back();
        }
        minDeque.push_back(right);

        while (arr[maxDeque.front()] - arr[minDeque.front()] > k) {
            left++;
            if (maxDeque.front() < left) {
                maxDeque.pop_front();
            }
            if (minDeque.front() < left) {
                minDeque.pop_front();
            }
        }

        maxLength = max(maxLength, right - left + 1);
        right++;
    }

    return maxLength;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << longestSubarrayWithDifference(arr, k) << endl;

    return 0;
}
