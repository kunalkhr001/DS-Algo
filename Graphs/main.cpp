#include <iostream>
#include<vector>

using namespace std;

vector<int>* getPathDFS()
{
    visited[v1]=true;
    if(v1==v2)
    {
       vector<int>* ans=new vector<int>;
       ans.push_back(v1);
       return ans;
    }

    for(int i=0;i<V;i++)
    {
        if(ans!=NULL)
        {
            ans->push_back(v1);
            return ans;
        }
    }
    return NULL;
}

void dfs(int **adjMatrix,int vertex,int V,bool *visited)
{
    cout<<vertex<<" ";
    visited[vertex]=true;
    for(int i=0;i<V;i++)
    {
        if(adjMatrix[vertex][i]!=0 && !visited[i])
        {
            dfs(adjMatrix,i,V,visited);
        }
    }
}

void dfs(int **adjMatrix,int V)
{
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(!visited[i])   // for each either connected or unconnected nodes
        {
            dfs(adjMatrix,i,V,visited);
            cout<<endl;
        }
    }


}

// for bfs to get all connected or unconnected nodes include queue part in loop as well

int main() {
    int V, E;
    cin >> V >> E;
  	int** adjMatrix=new int*[V];
    for(int i=0;i<V;i++)
    {
        adjMatrix[i]=new int[V];
        for(int j=0;j<V;j++)
            adjMatrix[i][j]=0;
    }

    for(int i=0;i<E;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adjMatrix[v1][v2]=1;
        adjMatrix[v2][v1]=1;
    }

  	getPathDFS(adjMatrix,V);





  return 0;
}
