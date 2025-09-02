#include <bits/stdc++.h>
using namespace std;


pair<int,int> partitionDualPivot(vector<int>& arr, int low, int high) {
    int p = arr[low], q = arr[high];


    if (p > q) swap(arr[low], arr[high]), swap(p, q);

    int lt = low + 1, gt = high - 1, i = low + 1;

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

    lt--, gt++;
    swap(arr[low], arr[lt]);
    swap(arr[high], arr[gt]);

    return {lt, gt};
}
void dualPivotQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
       pair<int,int> pivots = partitionDualPivot(arr, low, high);
int lp = pivots.first;
int rp = pivots.second;


       
        dualPivotQuickSort(arr, low, lp - 1);   
        dualPivotQuickSort(arr, lp + 1, rp - 1);
        dualPivotQuickSort(arr, rp + 1, high);  
    }
}

int main() {
    vector<int> arr = {4, 7, 2, 9, 1, 5};

    dualPivotQuickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
