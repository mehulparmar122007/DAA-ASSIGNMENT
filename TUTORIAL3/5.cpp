#include <bits/stdc++.h>
using namespace std;

// Partition with custom pivots (p, q)
pair<int,int> partitionDualPivot(vector<int>& arr, int low, int high, int p, int q) {
    // Ensure pivots are in correct order
    if (p > q) swap(p, q);

    int lt = low, i = low, gt = high;

    while (i <= gt) {
        if (arr[i] < p) {
            swap(arr[i], arr[lt]);
            lt++;
            i++;
        }
        else if (arr[i] > q) {
            swap(arr[i], arr[gt]);
            gt--;
        }
        else {
            i++;
        }
    }

    return {lt, gt};
}

// Dual Pivot QuickSort with custom pivots
void dualPivotQuickSort(vector<int>& arr, int low, int high, int p, int q) {
    if (low < high) {
        auto [lp, rp] = partitionDualPivot(arr, low, high, p, q);

        // Left side (< p)
        dualPivotQuickSort(arr, low, lp - 1, p, q);

        // Middle part (between p and q)
        dualPivotQuickSort(arr, lp, rp, p, q);

        // Right side (> q)
        dualPivotQuickSort(arr, rp + 1, high, p, q);
    }
}

int main() {
    vector<int> arr = {4, 7, 2, 9, 1, 5};

    int p = 2, q = 7; // custom pivots

    dualPivotQuickSort(arr, 0, arr.size() - 1, p, q);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
