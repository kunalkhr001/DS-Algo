#include <iostream>
#include<map>
#include<vector>

using namespace std;

void printIntersection(int *arr1,int m,int *arr2,int n)
{
    map<int ,int> map;
    for(int i=0;i<m;i++)
    {
        if(!map.count(arr1[i]))
        {
            map[arr1[i]]=1;
        }
        else
        {
            int oldFreq=map[arr1[i]];
            map[arr1[i]]=oldFreq+1;
        }
        //map[arr1[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        if(map.count(arr2[i]))
        {
            if(map[arr2[i]])
            {
                cout<<arr2[i]<<endl;
                map[arr2[i]]-=1;
            }

        }

    }
}

vector<int> removeDuplicates(int *arr,int size)
{
    vector<int> v;
    map<int ,int> map;
    for(int i=0;i<size;i++)
        map[arr[i]]++;
    for(int i=0;i<size;i++)
    {
        if(map[arr[i]]==1)
            v.push_back(arr[i]);
        else
        {

            map[arr[i]]--;
        }
    }
    return v;
}

int main()
{
    int arr3[]={6,6,6};
    int arr1[]={8,3,2,0,6,8};
    int m=6,n=5;
    int arr2[]={8,8,6,8,2,8,8,2};
    //printIntersection(arr1,m,arr2,n);
    vector<int> v=removeDuplicates(arr3,3);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}
