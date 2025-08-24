#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int> &arr, int left, int mid, int right) {
    long long count = 0;
    vector<int> temp;

    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += (mid - i + 1);  
        }
    }


    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }

    return count;
}

long long mergeSort(vector<int> &arr, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "No of inversions is " << mergeSort(arr, 0, n - 1) << endl;
    return 0;
}
