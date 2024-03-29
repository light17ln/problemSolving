#include <bits/stdc++.h>
using namespace std;

int maxSubarraySize(vector<int>& arr, int S) {
    int n = arr.size();
    int result = 0;

    for (int size = 1; size <= n; ++size) {
        int currSum = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= size)
                currSum -= arr[i - size];
            currSum += arr[i];
            if (i >= size - 1 && currSum > S)
                break;
            if (i >= size - 1)
                result = size;
        }
    }

    return result;
}

int main() {
    vector<int> A = {1, 3, 4, 2};
    int S = 7;

    cout << maxSubarraySize(A, S) << endl; // Output: 2

    return 0;
}