#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V,E;
	list<int> *adj;
	public:
		Graph()
		{
			cout<<endl<<"Enter the no of vertices and edges:";
			cin>>V>>E;
			
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
		bool isCycle();
		bool isCyclicUtil(int v,bool visited[],int parent);
};

bool Graph::isCycle()
{
	bool* visited=new bool[V];
	
	for(int i=0;i<V;i++)
	visited[i]=false;
	
	if(isCyclicUtil(0,visited,-1))
	return false;
	
	for(int u=0;u<V;u++)
	    if(!visited[u])
	    return false;
	    
	return true;
}

bool Graph::isCyclicUtil(int v,bool visited[],int parent)
{
    visited[v]=true;	
	
	list<int>::iterator it;
	for(it=adj[v].begin();it!=adj[v].end();++it)
	{
		if(!visited[*it])
		{
			if(isCyclicUtil(*it,visited,v))
			return true;
		}
		else
		if(*it!=parent)
		return true;
	}
	
	return false;
}

int main()
{
	Graph g;
	if(g.isCycle())
	cout<<endl<<"Given graph is a tree";
	else
	cout<<endl<<"Given graph is not a tree";
}
