#include <bits/stdc++.h>

using namespace std;

bool relaxEdge(int **adjM,int *distance,int n)
{
    bool relax=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adjM[i][j]!=0)
            {
                int dist=distance[i]+adjM[i][j];
                if(dist<distance[j])
                {
                    distance[j]=dist;
                    relax=true;
                }
            }
        }
    }
    return relax;
}

void bell(int **adjM,int n)
{
    int *distance=new int[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    int n1=n-1;
    while(n1--)
    {
        bool relax=relaxEdge(adjM,distance,n);
        if(!relax)
        {
            break;
        }
    }
    if(n1>0)
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<" "<<distance[i]<<endl;
        }   
    }
    else
    {
        bool relax=relaxEdge(adjM,distance,n);
        if(relax)
        {
            cout<<"Negative cycle exists\n";
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                cout<<i<<" "<<distance[i]<<endl;
            }   
        }
    }
}

int main() {
    int n,e;
    cin>>n>>e;
    int **adjM=new int*[n];
    //bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        adjM[i]=new int[n];
        //visited[i]=false;
        for(int j=0;j<n;j++)
        {
            adjM[i][j]=0;
        }
    }
    while(e--)
    {
        int n1,n2,c;
        cin>>n1>>n2>>c;
        adjM[n1][n2]=c;
    }
    bell(adjM,n);
    return 0;
}
