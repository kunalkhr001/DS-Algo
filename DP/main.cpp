#include <iostream>
#include<algorithm>

using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int coinChangeDP(int n,int *d,int k,int **dp)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(k==0)
        return 0;
    if(dp[n][k]>=0)
        return dp[n][k];
    int option1=coinChangeDP(n-d[0],d,k,dp);
    int option2=coinChangeDP(n,d+1,k-1,dp);
    dp[n][k]=option1+option2;
    return dp[n][k];
}


int coinChange(int n,int *d,int k)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(k==0)
        return 0;
    int option1=coinChange(n-d[0],d,k);
    int option2=coinChange(n,d+1,k-1);
    return option1+option2;
}

int countStepsTo1(int n){
    if(n==1)
        return 0;
    int ans=1+countStepsTo1(n-1);
    if(n%2==0)
        ans=min(ans,1+countStepsTo1(n/2));
    if(n%3==0)
        ans=min(ans,1+countStepsTo1(n/3));
    return ans;
}

int countStepsTo1DP(int n,int *arr){
    if(n==1)
        return 0;
    if(arr[n]>0)
        return arr[n];
    int ans=1+countStepsTo1DP(n-1,arr);
    if(n%2==0)
        ans=min(ans,1+countStepsTo1DP(n/2,arr));
    if(n%3==0)
        ans=min(ans,1+countStepsTo1DP(n/3,arr));
    arr[n]=ans;
    return ans;
}

int countStepsTo1DP2(int n){
    int *arr=new int[n+1];
    arr[1]=0;
    for(int i=2;i<=n;i++)
    {
        int ans=1+arr[i-1];
        if(i%2==0)
            ans=min(ans,1+arr[i/2]);
        if(i%3==0)
            ans=min(ans,1+arr[i/3]);
        arr[i]=ans;
    }

    return arr[n];
}

long staircase(int n){

  long *storage=new long[n+1];
    storage[0]=1;
    storage[1]=1;
    storage[2]=2;


    for(int i=3;i<=n;i++)
    {
        storage[i]=storage[i-1]+storage[i-2]+storage[i-3];
    }
    return storage[n];

}

int fibDP(int n)
{
    int *storage=new int[n+1];
    storage[0]=0;
    storage[1]=1;
    for(int i=2;i<=n;i++)
    {
        storage[i]=storage[i-1]+storage[i-2];
    }
    return storage[n];
}

int main()
{
    /*
    //cout << staircase(10);
    int k=2;
    int *d=new int[k];
    for(int i=0;i<k;i++)
        cin>>d[i];
    cout<<coinChange(15,d,k);
    //cout<<coinChangeDP(4,d,2,dp);
    */
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(W, wt, val, n);
    return 0;
}
