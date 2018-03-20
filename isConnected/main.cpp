#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void connectedComponents(unordered_map<int,vector<int>*> &adjacencyList,unordered_map<int,bool> &visited,vector<int>* smallOutput,int v)
{
    smallOutput->push_back(v);
    visited[v]=true;
    vector<int>* adjVertices=adjacencyList[v];
    for(int i=0;i<adjVertices->size();i++)
    {
        if(visited.count(adjVertices->at(i))==0)
        {
            connectedComponents(adjacencyList,visited,smallOutput,adjVertices->at(i));

        }
    }
}

vector<vector<int>*>* allConnectedComponents(unordered_map<int,vector<int>*> &adjacencyList)
{
    unordered_map<int,bool> visited;
    vector<vector<int>*> *output=new vector<vector<int>*>;
    int i=0;
    while(visited.size()!=adjacencyList.size())
    {
        for(;i<adjacencyList.size();i++)
        {
            if(visited.count(i)==0)
            {
                vector<int> *smallOutput=new vector<int>;
                connectedComponents(adjacencyList,visited,smallOutput,i);
                output->push_back(smallOutput);
            }
        }
    }
    return output;
}

void dfs(unordered_map<int,vector<int>*> &adjacencyList,int v1,unordered_map<int,bool> &visited)
{
    vector<int>* adjacentVertices=adjacencyList[v1];
    visited[v1]=true;
    for(int i=0;i<adjacentVertices->size();i++)
    {
        if(visited.count(adjacentVertices->at(i))==0)
        {
            dfs(adjacencyList,adjacentVertices->at(i),visited);
        }
    }
}

bool isConnected(unordered_map<int,vector<int>*> &adjacencyList)
{
    unordered_map<int,bool> visited;
    int startVertex=adjacencyList.begin()->first;
    dfs(adjacencyList,startVertex,visited);
    return visited.size()==adjacencyList.size();
}

int main()
{
    int v,e;
    cin>>v>>e;
    unordered_map<int,vector<int>*> adjacencyList;
    for(int i=0;i<v;i++)
    {
        vector<int>* v1=new vector<int>;
        adjacencyList[i]=v1;
    }
    int count=1;
    while(count++<=e)
    {
        int source,dest;
        cin>>source>>dest;
        adjacencyList[source]->push_back(dest);
        adjacencyList[dest]->push_back(source);
    }
    /*if(isConnected(adjacencyList))
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
        */
    vector<vector<int>*> *output=allConnectedComponents(adjacencyList);
    for(int i=0;i<output->size();i++)
    {
        vector<int> *component=output->at(i);
        sort(component->begin(),component->end());
        for(int j=0;j<component->size();j++)
        {
            cout<<component->at(j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
