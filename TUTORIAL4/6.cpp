#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "enter number of licenses: ";
    cin >> n;

    vector<double> rate(n);
    cout << "enter rates: ";
    for (int i = 0; i < n; i++) cin >> rate[i];

    sort(rate.begin(), rate.end(), greater<double>());

    double total = 0;
    for (int i = 0; i < n; i++) {
        total += 1000 * pow(rate[i], i);
    }

    cout << "minimum total cost = " << total << endl;
    cout << "order of purchase (rates): ";
    for (double r : rate) cout << r << " ";
    cout << endl;

    return 0;
}
