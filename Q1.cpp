#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void mean(vector<long> grad,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=grad[i];
    }
    cout<<"Mean of grades : "<<(double)sum/n<<endl;
}
double median(vector<long> arr,int n)
{
    //if the size of array is odd then median will be its n/2 element
    //if size of array is even then median will be the mean of its n/2 ans (n/2)-1 element
    if(n%2!=0)
    {
        return arr[n/2];
    }
    else
    {
        return (double)(arr[n/2]+arr[(n/2)-1])/2;
    }

}


vector<int> mode(vector<long> grades,int n){

    //mode of grade list will be the grade with maximum ocuurence in the list
    //so we use unordered_map to show its key and value as grades and its frequency
    unordered_map<int, int> freq;
    
    for(int i=0; i<n; i++)
    {
        freq[grades[i]]++;
    }

    int maxfreq=0;
    for(auto i:freq)
    {
        if(i.second>maxfreq)
        {
            maxfreq=i.second;
        }
    }
    //for multimodal grade list
    vector<int> ans;
    for(auto i:freq)
    {
        if(i.second==maxfreq)
        {
            ans.push_back(i.first);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;
    cout<<"Number of name pairs : ";
    cin>>n;
    vector<string> name(n);
    vector<long> grades(n);

    //get name pairs from user
    cout<<"Enter their Names : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>name[i];
    }
    cout<<"Enter their Grades : "<<endl;
    //get grade pairs from user
    for(int i=0;i<n;i++)
    {
        cin>>grades[i];
    }

    //Mean of grades;
    //mean of the grades can be decimal
    mean(grades,n);

    //median of grades
    //median of grades can be decimal
    double res=median(grades,n);
    cout<<"Median of grades : "<<res<<endl;

    //mode of grades
    cout<<"Mode of grades is/are : ";
    vector<int> res2=mode(grades,n);
    for(int i=0;i<res2.size();i++)
    {
        cout<<res2[i]<<" ";
    }
    cout<<endl;

}