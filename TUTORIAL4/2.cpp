#include <bits/stdc++.h>
using namespace std;


bool comp(pair<int,int> p1, pair<int,int> p2) {
   
    return p1.second > p2.second;
}

int main() {
    int n;
    cout<<"enter the number of jobs : ";
    cin>>n;
    vector<pair<int,int>> d_p;//d_p => deadline , profit
    int max_deadline= 0;
    for(int i=0;i<n;i++)
    {
        int d,p;
        cin>>d>>p;
        max_deadline = max(max_deadline , d);
        d_p.push_back({d,p});

    }
    //sort based on profit;
    
    sort(d_p.begin() ,d_p.end(),comp);
    vector<int> dead(max_deadline + 1 , -1);
    int max_profit = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=d_p[i].first;j>=1;j--)
        {
            if(dead[j]==-1)
            {
                dead[j] = 1;
                max_profit += d_p[i].second;
                break;
            }
        }
    }
    cout<<"maximum profit we can take is : "<<max_profit<<endl;
}
