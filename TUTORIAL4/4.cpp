#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of houses : ";
    cin >> n;
    vector<int> House(n);
    for (int i = 0; i < n; i++) {
        cin >> House[i];
    }

    sort(House.begin(), House.end());

    if (n == 0) {
        cout << "Minimum number of towers required is: 0\n";
        return 0;
    }

    int min_tower = 0;
    int i = 0;

    while (i < n) {
       
        int loc = House[i] + 4;
        while (i < n && House[i] <= loc) i++;

       
        int towerPos = House[i - 1];
        cout<<towerPos<<"\t";
        min_tower++;


    loc = towerPos + 4;
        while (i < n && House[i] <= loc) i++;
    }

    cout << "Minimum number of towers required is: " << min_tower << endl;
}
