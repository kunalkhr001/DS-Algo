#include<algorithm>
#include<climits>
#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    int maximum=INT_MIN;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i+1<n;i++)
    {
        int x=int(a[i]^a[i+1]);
        if(x>maximum)
            maximum=x;
    }
    cout<<maximum<<endl;
    return 0;
}
