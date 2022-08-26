#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

vector<pair<int, int>> sort(unordered_map<int, int>& arr){
    vector<pair<int, int>> ans;
    
    for(auto i: arr)
    {
        ans.push_back(i);
    }
        
    sort(begin(ans), end(ans), cmp);
    return ans;
}

int main()
{
    cout<<"Enter the number of pairs you want to enter : ";
    int n;
    cin>>n;
    unordered_map<int, int> arr;
    cout<<"Enter Key and value pairs : "<<endl;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr[a] = b;
    }
    
    vector<pair<int, int>> result = sort(arr);
    cout<<"After Sorting map based on values instead of keys : "<<endl;
    for(auto i: result){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    return 0;
}