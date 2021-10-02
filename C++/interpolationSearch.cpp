// Given a sorted array of n uniformly distributed values arr[], write a function to search for a particular element x in the array. 

// Linear Search finds the element in O(n) time, Jump Search takes O(√ n) time and Binary Search take O(Log n) time. 

// The Interpolation Search is an improvement over Binary Search for instances, where the values in a sorted array are uniformly distributed. Binary Search always goes to the middle element to check. On the other hand, interpolation search may go to different locations according to the value of the key being searched. For example, if the value of the key is closer to the last element, interpolation search is likely to start search toward the end side.

#include<iostream>
#include<unistd.h>
using namespace std;

int interpolationSearch(int arr[],int n,int x){
    int hi = n-1,lo = 0;
    while(lo<=hi && x>=arr[lo] && x<=arr[hi])
    {
        if(lo == hi){
            if(arr[lo]==x){
                return lo;
            }
            return -1;
        }
        int pos = lo + ((x-arr[lo])*(hi-lo))/(arr[hi]-arr[lo]);
        if(arr[pos]<x)
        {lo = pos+1;}
        else if(arr[pos]>x)
        {hi = pos-1;}
        else if(arr[pos]==x)
        {return pos;}

    }
    return -1;
}

int main()
{
    int n,m;
    cout<<"ENTER ELEMENT TO SEARCH"<<endl;
    cin>>m;
    cout<<"ENTER NUMBER OF ELEMENTS IN THE ARRAY: "<<endl;
    cin>>n;
    int arr[n+1];
    cout<<"ENTER ELEMENTS"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int index = interpolationSearch(arr,n,m);
    if(index!=-1)    
    cout<<"ELEMENT FOUND AT INDEX "<<index<<endl;
    else{
        cout<<"ELEMENT NOT FOUND"<<endl;
    }
    return 0;
}