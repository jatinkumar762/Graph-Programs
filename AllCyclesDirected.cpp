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
			}
		}
		~Graph()
		{
			delete []adj;
		}
		void isCycle();
		void isCyclicUtil(int v,bool visited[],bool rec[]);   
   	
};

void Graph::isCyclicUtil(int v,bool visited[],bool rec[])
{
     if(!visited[v])
	 {
          visited[v]=true;	 	
	 	  rec[v]=true;
	 	  
	 	  circle[k++]=v;
	 	  
	 	  list<int>::iterator it;
	 	  for(it=adj[v].begin();it!=adj[v].end();++it)
	 	  {
	 	      if( !visited[*it] )
			  {
			  	isCyclicUtil(*it,visited,rec);
			  } 
	 	  	  else
	 	  	  if(rec[*it])
	 	  	  {
	 	  	  	for(int i=0;i<k;i++)
	 	  	  	cout<<circle[i]<<" ";
	 	  	  	cout<<endl;
	 	  	  }
	 	  	
	 	  }
	 	     rec[v]=false;
			 visited[v]=false;
			 k--;
	 }	
	
}

void Graph::isCycle()
{
	bool *visited=new bool[V];
	bool *rec=new bool[V];
	
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
		rec[i]=false;
	}
	   isCyclicUtil(0,visited,rec);
	
}


int main()
{
	Graph g;
		cout<<"All possible Cycles :"<<endl;
	g.isCycle();

	return 0;
}
