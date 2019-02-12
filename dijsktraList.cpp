#include <bits/stdc++.h>
using namespace std;


int findV(int* distance, bool* visited, int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex==-1 || distance[i]<distance[minVertex]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}

void dijkstra(unordered_map<int,vector<vector<int>>> list,int n)
{
    int *distance=new int[n];
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    distance[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int minVertex=findV(distance,visited,n);
        visited[minVertex]=true;
        for(int j=0;j<list[minVertex].size();j++)
        {
            if(!visited[list[minVertex][j][0]])
            {
                int dist= distance[minVertex] + list[minVertex][j][1];
                if(dist<distance[list[minVertex][j][0]])
                {
                    distance[list[minVertex][j][0]]=dist;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)
        {
            cout<<i<<" "<<distance[i]<<endl;
        }

}

int main() {
    unordered_map<int,vector<vector<int>>> list;
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int n1,n2,w;
        cin>>n1>>n2>>w;
        vector<int> v;
        v.push_back(n2);
        v.push_back(w);
        list[n1].push_back(v);
        v.clear();
        v.push_back(n1);
        v.push_back(w);
        list[n2].push_back(v);
    }
    dijkstra(list,n);
    return 0;
}
