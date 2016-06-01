#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V,E;
	int **adj;
	list<int> *str;
	public:
		Graph()
		{
		   	cout<<"Enter the no of vertices and edges:"<<endl;
		   	cin>>V>>E;
		   	adj=new int*[V];
		   	for(int i=0;i<V;i++)
		   	adj[i]=new int[V];
		   	
		   	str=new list<int>[V];
		   	
		   	int v1,v2;
		   	for(int i=0;i<E;i++)
		   	{
		   		cout<<endl<<"Enter vertices for edge :"<<i+1;
		   		cin>>v1>>v2;
		   		
		   	     adj[v1-1][v2-1]=1;
		   	     adj[v2-1][v1-1]=1;
		   	}
		}
		~Graph()
		{
			for(int i=0;i<V;i++)
			delete []adj[i];
			delete []adj;
		}
		
		void graphColoring();
};

void Graph::graphColoring()
{
	int result[V];
	int available[V];
	
	result[0]=0;  //assign color 0 to vertex-0
	str[0].push_back(0);
	
	for(int i=1;i<V;i++)
	result[i]=-1;
	
	for(int i=0;i<V;i++)    // Color is available
	available[i]=0;
	
	for(int u=1;u<V;u++)
	{
		for(int i=0;i<V;i++)
		{
			if(adj[u][i]==1)
		    if(result[i]!=-1)
		    available[result[i]]=1;
	    }
	    
		int clr;
		for(clr=0;clr<V;clr++)
		if(available[clr]==0)
		break;
		
		result[u]=clr;
		str[clr].push_back(u);
		
			for(int i=0;i<V;i++)
			{
				if(adj[u][i]==1)
		    	if(result[i]!=-1)
		    	available[result[i]]=0;
		    }
		  //  cout<<result[u];
		
	}
	
	for(int i=0;i<V;i++)
	{
		cout<<"Vertex :"<<i+1<<" Color: "<<result[i]<<endl;
	}
	cout<<endl<<endl;
	list<int>::iterator j;
	int i;
	for(i=0;i<V&&str[i].begin()!=str[i].end();i++)
	{
		cout<<"Color :"<<i<< "  Vertex ";
		for(j=str[i].begin();j!=str[i].end();++j)
		cout<<" "<<(*j)+1;
		cout<<endl;
	}
	
}

int main()
{
	Graph g;
	g.graphColoring();
	
	return 0;
}
