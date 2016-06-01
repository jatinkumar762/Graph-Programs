#include<stdio.h>
#include<list>
#include<stdlib.h>
#include<iostream>
using namespace std;

int V,E,i,j,v1,v2;
int **adj;

void BFS(int s)
{
	bool *visited=new bool[V];
	
	for(int i=0;i<V;i++)
	visited[i]=false;
	
	std::list<int> queue;
	
	visited[s]=true;
	queue.push_back(s);
	
	std::list<int>::iterator i;
	
	while(!queue.empty())
	{
		s=queue.front();
		cout<<(s+1)<<" ";
		queue.pop_front();
		
		for(int i=0;i<V;i++)
		{
			if(adj[s][i]==1)
			{
				if(!visited[i])
				{
					visited[i]=true;
					queue.push_back(i);
				}
			}
		}
	}
		
}

void DFS_Util(int s,bool *visited)
{
	visited[s]=true;
	cout<<(s+1)<<" ";
	
	for(i=0;i<V;i++)
	{
		if(adj[s][i]==1)
		{
			if(!visited[i])
			{
				DFS_Util(i,visited);
			}
		}
	}
}

void DFS()
{
    bool *visited=new bool[V];
  	for(i=0;i<V;i++)
  	visited[i]=false;
  	
    for(int i=0;i<V;i++) 
	if(visited[i]==false) 	
  	DFS_Util(i,visited);
}

int main()
{
    
    printf("Enter the no. of Vertices:\n");
	scanf("%d",&V);	
	printf("Enter the no. of Edges:\n");
	scanf("%d",&E);
	
	adj=(int**)malloc(sizeof(int*)*V);
	for(i=0;i<V;i++)
	adj[i]=(int*)malloc(sizeof(int)*V);	
	
	for(i=0;i<V;i++)
	 for(j=0;j<V;j++)
	   adj[i][j]=0;

	   
	for(i=0;i<E;i++)
	{
		printf("\nEnter vertices for edge:%d  --->",i+1);
		scanf("%d %d",&v1,&v2);
		
		adj[v1-1][v2-1]=1;
		adj[v2-1][v1-1]=1;
		
	}
	
	printf("\n\nAdjacency Matrix :");
	for(i=0;i<V;i++)
	{
		printf("\n");
		for(j=0;j<V;j++)
		{
			printf("%d ",adj[i][j]);
		}
	}	

	
	printf("\n\nBreadth First Search :");
	BFS(1);
	
	printf("\n\nDepth First Search   :");
	DFS();
	
	return 0;
} 
