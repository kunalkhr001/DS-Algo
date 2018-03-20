#include<iostream>
#include<queue>
#include<map>
using namespace std;

vector<int>* getPathBFS(int **adjMatrix,int V,int sv,int ev)
{
    queue<int > bfsQ;
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    bfsQ.push(sv);
    visited[sv]=true;
    bool done=false;
    map<int,int> parent;
    while(!bfsQ.empty() && !done)
    {
        int front=bfsQ.front();
        bfsQ.pop();
        for(int i=0;i<V;i++)
        {
            if(adjMatrix[front][i]!=0 && !visited[i])
            {
                parent[i]=front;
                bfsQ.push(i);
                visited[i]=true;
                if(i==ev)
                {
                    done=true;
                    break;
                }
            }
        }
    }
    delete[] visited;
    if(!done)
        return NULL;
    else
    {
        vector<int>* output=new vector<int>();
        int current=ev;
        output->push_back(ev);
        while(current!=sv)
        {
            current=parent[current];
            output->push_back(current);
        }
        return output;
    }
}

vector<int>* getPathDFSHelper(int **adjMatrix,int V,int v1,int v2,bool *visited)
{
    if(v1==v2)
    {
        vector<int>* output=new vector<int>();
        output->push_back(v1);
        return output;
    }
    visited[v1]=true;
    for(int i=0;i<V;i++)
    {
        if(adjMatrix[v1][i]!=0 && !visited[i])
        {
            vector<int>* smallOutput=getPathDFSHelper(adjMatrix,V,i,v2,visited);
            if(smallOutput!=NULL)
            {
                smallOutput->push_back(v1);
                return smallOutput;
            }
        }
    }
        return NULL;
}

vector<int>* getPathDFS(int **adjMatrix,int V,int v1,int v2)
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    vector<int>* output=getPathDFSHelper(adjMatrix,V,v1,v2,visited);
    delete[] visited;
    return output;
}

bool hasPath(int **adjMatrix,int v1,int v2,int V,bool *visited)
{
    if(v1==v2)
        return true;
    visited[v1]=true;
    for(int i=0;i<V;i++)
    {
        if(adjMatrix[v1][i]!=0 && !visited[i])
        {
            bool smallAns=hasPath(adjMatrix,i,v2,V,visited);
            if(smallAns)
                return true;
        }
    }
    return false;
}

void BFSRecursive(int **adjMatrix,int vertex,int V,queue<int> q,bool *visited)
{
    if(!q.empty())
    {
        cout<<q.front()<<" " ;
        visited[q.front()]=true;
        q.pop();
    }
    else
        return;
    BFSRecursive(adjMatrix,q.front(),V,q,visited);
}

void BFS(int **adjMatrix,int V)
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty())
    {
        int currVertex=q.front();
        q.pop();
        cout<<currVertex<<" ";
        for(int i=0;i<V;i++)
        {
            if(adjMatrix[currVertex][i]!=0 && !visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

int main()
{
    int V,E;
    cin>>V>>E;
    int **adjMatrix=new int *[V];
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        adjMatrix[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            adjMatrix[i][j]=0;
        }
        visited[i]=false;
    }
    for(int i=0;i<E;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adjMatrix[v1][v2]=1;
        adjMatrix[v2][v1]=1;
    }
    //BFS(adjMatrix,V);
    //BFSRecursive(adjMatrix,0,V,q,visited);
    /*bool path=hasPath(adjMatrix,0,3,V,visited);
    if(path)
        cout<<"Yes";
    else
        cout<<"No";
        */
    /*
    int sv,ev;
    cin>>sv>>ev;
    vector<int>* output=getPathDFS(adjMatrix,V,sv,ev);
    if(output!=NULL)
    {
        cout<<"Path: ";
        for(int i=0;i<output->size();i++)
        {
            cout<<output->at(i)<<" ";
        }

    }
    else
    {
        cout<<"No Path exists"<<endl;
    }
    delete output;
    */
     int sv,ev;
    cin>>sv>>ev;
    vector<int>* output=getPathBFS(adjMatrix,V,sv,ev);
    if(output!=NULL)
    {
        cout<<"Path: ";
        for(int i=0;i<output->size();i++)
        {
            cout<<output->at(i)<<" ";
        }

    }
    else
    {
        cout<<"No Path exists"<<endl;
    }
	return 0;
}
