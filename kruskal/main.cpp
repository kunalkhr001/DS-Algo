#include <iostream>
#include <algorithm>
using namespace std;

//MST using Kruskal Algorithm (Union Find  Algorithm, better option is Union Rank & path Compression )

class Edge
{
  public:
  int source;
  int dest;
  int weight;
};

bool compare(Edge e1,Edge e2)
{
  return e1.weight<e2.weight;
}

int findParent(int v,int* parent)
{
  if(parent[v]==v)
    return v;
  return findParent(parent[v],parent);

}

void kruskals(Edge *input,int n,int E)
{
  sort(input,input+E,compare);
  Edge* output=new Edge[n-1];
  int *parent=new int[n];
  for(int i=0;i<n;i++)
    parent[i]=i;
  int count=0,i=0;
  while(count!=n-1)
  {
    Edge currentEdge=input[i];
    int sourceParent=findParent(currentEdge.source,parent);
    int destParent=findParent(currentEdge.dest,parent);
    if(sourceParent!=destParent)
    {
      output[count]=currentEdge;
      count++;
      parent[sourceParent]=destParent;
    }
    i++;
  }
  for(int i=0;i<n-1;i++)
  {
    if(output[i].source<output[i].dest)
      cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    else
      cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
  }
}

int main()
{
  int V, E;
  cout<<"Input no. of vertices & edges:"<<endl;
  cin >> V >> E;
  Edge *input=new Edge[E];
  for(int i=0;i<E;i++)
  {
    int s,d,w;
    cout<<"Enter Source, Destination ,Weight:";
    cin>>s>>d>>w;
    input[i].source=s;
    input[i].dest=d;
    input[i].weight=w;
  }
  cout<<"MST using kruskals Algorithm:"<<endl;
  kruskals(input,V,E);

  return 0;
}
