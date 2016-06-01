#include<iostream>
#include<list>
using namespace std;

int circle[100];
int k=0;

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
		void isCycle();
		void isCyclicUtil(int v,bool visited[],int parent);
};

void Graph::isCycle()
{
	bool* visited=new bool[V];
	
	for(int i=0;i<V;i++)
	visited[i]=false;
	
//	for(int u=0;u<V;u++)
//	    if(!visited[u])
	     isCyclicUtil(0,visited,-1);
	     
}

void Graph::isCyclicUtil(int v,bool visited[],int parent)
{
    visited[v]=true;	
	circle[k++]=v;
	
	list<int>::iterator it;
	
	for(it=adj[v].begin();it!=adj[v].end();++it)
	{
		if(!visited[*it])
		{
			isCyclicUtil(*it,visited,v);
		}
		else
		if(*it!=parent)
		{
		   for(int i=0;i<k;i++)
		   cout<<circle[i]<<" ";
		   cout<<endl;	
		}
	}
	visited[v]=false;
	k--;
}

int main()
{
	Graph g;
	cout<<endl<<"All possible cycles :"<<endl;
	g.isCycle();
	//cout<<endl<<"Contain cycle";
	//else
	//cout<<endl<<"Doesn't Contain Cycle";
}
