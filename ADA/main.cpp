#include <iostream>
#include <algorithm>

using namespace std;

class Activity
{
    public:
    int start,finish;
};

class Job
{
    public:
    char id;
    int deadline,profit;
};

class Item
{
    public:
    int value,weight;
};

bool compareActivity(Activity a1,Activity a2)
{
    return a1.finish<a2.finish;
}

bool compareJob(Job j1,Job j2)
{
    return j1.profit>j2.profit;
}

bool compareKnapsack(Item a,Item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}

void selectionActivity(Activity arr[],int n)
{
    sort(arr,arr+n,compareActivity);
    cout<<"Following Activities are selected: "<<endl;
    int i=0;
    cout<<"("<<arr[i].start<<", "<<arr[i].finish<<"), ";
    for(int j=1;j<n;j++)
    {
        if(arr[j].start>=arr[i].finish)
        {
            cout<<"("<<arr[j].start<<", "<<arr[j].finish<<"), ";
            i=j;
        }
    }
}

void jobSequencing(Job arr[],int n)
{
    sort(arr,arr+n,compareJob);
    int result[n];
    bool slot[n];
    for(int i=0;i<n;i++)
        slot[i]=false;
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(slot[i])
            cout<<arr[result[i]].id<<" ";
    }
}

double fractionalKnapsack(int W,Item arr[],int n)
{
    sort(arr,arr+n,compareKnapsack);
    int currentWt=0;
    double finalValue=0;
    for(int i=0;i<n;i++)
    {
        if(currentWt+arr[i].weight<=W)
        {
            currentWt+=arr[i].weight;
            finalValue+=arr[i].value;
        }
        else
        {
            int remain=W-currentWt;
            finalValue+=arr[i].value*((double)remain/arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionActivity(arr, n);

    /*Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},{'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    jobSequencing(arr, n);
    */
    /*int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = "<< fractionalKnapsack(W, arr, n);
    */
    return 0;
}
