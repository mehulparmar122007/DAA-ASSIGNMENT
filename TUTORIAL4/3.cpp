// Problem Definition: Given character frequencies, construct an optimal prefix code using Huffman’s algo-
// rithm, minimizing the total cost of encoding.

// Example: Characters = {a : 5, b : 9, c : 12, d : 13, e : 16, f : 45} Huffman cost = 224.
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1 , pair<int,int> p2)
{
    return p1.second < p2.second;
}
int main()
{
    int n;
    cout<<"enter number of char : ";
    cin>>n;
    vector<pair<int,int>> freq(n);
    for(int i=0;i<n;i++)
    {
        int f;
        char c;
        cin>>c>>f;
        freq[i] = {c , f};

    }
    sort(freq.begin() , freq.end() , comp);
    int total = 0,prev=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        if(prev + freq[i].second < freq[i].second +  freq[i+1].second)
        {
            prev = freq[i].second +  freq[i].second;
            total+=freq[i].second +  freq[i].second;
        }
        else
        {
            total+=prev +  freq[i+1].second;
        }

    }






}