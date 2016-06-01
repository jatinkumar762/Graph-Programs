#include<iostream>
#include<list>
using namespace std;

class Graph
{
  int V,E,C;
  list<int> *adj;
  public:
       Graph()
	   {
	   	 	cout<<endl<<"Enter the no of vertices and edges:";
			cin>>V>>E;
			C=0;
			adj=new list<int>[V];
			
			int v1,v2;
			for(int i=0;i<E;i++)
			{
				cout<<endl<<"Enter the vertices for edge "<<i+1<<"  :";
				cin>>v1>>v2;
				adj[v1].push_back(v2);
	
				adj[v2].push_back(v1);
			}
	   }
	   ~Graph()
	   {
	   	delete []adj;
	   }	
       void dfs(int s,bool visited[]);	
       bool oneIsomorphism(Graph g);
       
};

void Graph::dfs(int s,bool visited[])
{
   visited[s]=true;
   list<int>::iterator it;
   for(it=adj[s].begin();it!=adj[s].end();++it)
   {
   	 if(!visited[*it])
   	   dfs(*it,visited);
   }	
   return;
}

bool Graph::oneIsomorphism(Graph g)
{
	bool *visited1=new bool[V];
	
	for(int i=0;i<V;i++)
	visited1[i]=false;
	
	for(int i=0;i<V;i++)
	   if(!visited1[i])
	   {
	     dfs(i,visited1);
	     C++;
       }
    cout<<C<<endl<<endl;
    
    bool *visited2=new bool[g.V];
    
    for(int i=0;i<g.V;i++)
	visited2[i]=false;
	
	for(int i=0;i<g.V;i++)
	   if(!visited2[i])
	   {
	     g.dfs(i,visited2);
	     g.C++;
       }
       
    int rank1=V-C;
    int rank2=g.V-g.C;
	
	cout<<rank1<<rank2<<endl;
	
	if( rank1!=rank2 )
	return false;
	
	int nullity1=E-rank1;
	int nullity2=E-rank2;
	
	cout<<nullity1<<nullity2<<endl;
	
	if( nullity1!=nullity2 )
	return false;
	
	return true;	
}

int main()
{
	Graph g1,g2;
	if(g1.oneIsomorphism(g2))
	{
		cout<<endl<<"one-isomorphic";
    }
	else
	{
	    cout<<endl<<"not isomorphic";
    }
	return 0;
}
