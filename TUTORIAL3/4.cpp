#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

 
    if (n == 1) {
        cout << "our peak element is : " << v[0] << endl;
        return 0;
    }
    if (v[0] > v[1]) {
        cout << "our peak element is : " << v[0] << endl;
        return 0;
    }
    if (v[n - 1] > v[n - 2]) {
        cout << "our peak element is : " << v[n - 1] << endl;
        return 0;
    }


    int low = 1, high = n - 2, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1]) {
           break;
        }
        else if (v[mid] > v[mid - 1]) {
            low = mid + 1; 
        }
        else {
            high = mid - 1;
        }
    }

    
    cout << "our peak element is : " << v[mid] << endl;
    return 0;
}
