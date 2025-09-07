#include <bits/stdc++.h>
using namespace std;

int main() {
    int cap, dist;
    cout << "enter tank capacity and target distance: ";
    cin >> cap >> dist;

    int m;
    cout << "enter number of petrol pumps: ";
    cin >> m;
    vector<int> pump(m);
    for (int i = 0; i < m; i++) cin >> pump[i];

    sort(pump.begin(), pump.end());

    if (dist <= cap) {
        cout << "minimum stops = 0\n";
        return 0;
    }

    int stop_count = 0;
    int pos = 0;
    int k = 0;
    vector<int> stop_list;

    while (pos + cap < dist) {
        int far = -1;

        while (k < m && pump[k] <= pos + cap) {
            far = pump[k];
            k++;
        }

        if (far == -1) {
            cout << "cannot reach destination (no reachable pump).\n";
            return 0;
        }

        stop_list.push_back(far);
        pos = far;
        stop_count++;
    }

    cout << "minimum stops = " << stop_count << '\n';
    cout << "stop positions: ";
    for (int s : stop_list) cout << s << " ";
    cout << '\n';
    return 0;
}
