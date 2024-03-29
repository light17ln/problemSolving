//METHOD:-1

#include <bits/stdc++.h>
using namespace std;

int minDaysToMakeBouquets(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (n < m * k) {
        return -1; // Not enough flowers to make m bouquets
    }

    int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        int bouquets = 0, flowers = 0;
        for (int i = 0; i < n; ++i) {
            if (bloomDay[i] <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        if (bouquets < m) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}