#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cout<<"enter position for smallest kth ele : ";
    cin>>k;
    vector<int> v = {5,6,7,3,2,1};
    sort(v.begin(),v.end());
    cout<<"kth smallest element is "<<v[k-1]<<endl;
}