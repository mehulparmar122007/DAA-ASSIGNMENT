#include <bits/stdc++.h>
using namespace std;

// Comparator: sort by value/weight ratio in descending order
bool comp(pair<int,int> p1, pair<int,int> p2) {
    double r1 = (double)p1.first / p1.second;
    double r2 = (double)p2.first / p2.second;
    return r1 > r2;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    int W;
    cout << "Enter the capacity of the bag: ";
    cin >> W;

    vector<int> values(n), weights(n);
    cout << "Enter values and weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    vector<pair<int,int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = {values[i], weights[i]};
    }

    
    sort(p.begin(), p.end(), comp);

    double max_total = 0.0;
    int i = 0;
    while (W > 0 && i < n) {
        if (p[i].second <= W) {
            W -= p[i].second;
            max_total += p[i].first;
        } else {
            max_total += (double)p[i].first * ((double)W / p[i].second);
            W = 0;
        }
        i++;
    }

    cout << "Maximum profit we can take is: " << max_total << endl;
    return 0;
}
