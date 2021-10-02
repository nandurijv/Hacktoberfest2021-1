// Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

// Input: 
// Items as (value, weight) pairs 
// arr[] = {{60, 10}, {100, 20}, {120, 30}} 
// Knapsack Capacity, W = 50; 

// Output: 
// Maximum possible value = 240 
// by taking items of weight 10 and 20 kg and 2/3 fraction 
// of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240


#include<iostream>
using namespace std;
#define MAX 100

struct item{
    int weight;
    int priority;
    int pperw;
    float x;
    char name[MAX];
}items[MAX];

void sortingBasedonPriority(int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(items[i].pperw<items[j].pperw){
                swap(items[i],items[j]);
            }
        }
    }
}

void displayList(int n){
    for(int i=0;i<n;i++)
    {
        cout<<items[i].name<<endl<<items[i].weight<<endl<<items[i].x<<endl;
    }
}

void toInclude(int n,int W){
    int weight=0;
    for(int i=0;i<n;i++){
        cout<<weight<<endl;
        if(weight==W){
            return;
        }
        if(weight+items[i].weight<W){
            items[i].x=1;
            weight+=items[i].weight;
        }
        else{
            items[i].x = 1.00*(W-weight)/items[i].weight;
            weight+=items[i].x*items[i].weight;
            return;
        }
    }
}
int main(){
    int n,W;
    cout<<"ENTER THE NUMBER OF ITEMS"<<endl;
    cin>>n;
    cout<<"ENTER THE MAX CAPACITY"<<endl;
    cin>>W;
    for(int i=0;i<n;i++){
        cin>>items[i].name;
        cin>>items[i].weight;
        cin>>items[i].priority;
        items[i].pperw = items[i].priority/items[i].weight;
        items[i].x = 0;
    }

    sortingBasedonPriority(n);
    toInclude(n,W);
    displayList(n);
    return 0;
}