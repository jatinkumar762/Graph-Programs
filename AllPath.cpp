#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

int V,E,v1,v2;
int **adj;
int path[10],path_index=0; 

void DFS_Util(int s,bool *visited)
{
	int i;
	visited[s]=true;
	path[path_index]=s+1;
	path_index++;
	
	if(s!=v2)
	{	
	 	for(i=0;i<V;i++)
		{
			if(adj[s][i]==1)
			{
				if(!visited[i])
				{
				//	cout<<"In "<<i<<endl;
					DFS_Util(i,visited);
				//	cout<<"Out "<<i<<endl;
				}			
			}
		}
	}
	else
	{
		for(int i=0;i<path_index;i++)
		cout<<path[i]<<" ";
		cout<<endl;
	}
		
	path_index--;
	visited[s]=false;
	return;
}

void DFS()
{
	int i,j;
    bool *visited=new bool[V];
  	for(i=0;i<V;i++)
  	visited[i]=false;
  	
  	cout<<endl<<"Enter pair of vertices :";
  	cin>>v1>>v2;
  	v1-=1;
  	v2-=1;
   // for(int i=0;i<V;i++) 
  // if(visited[i]==false) 	
  	DFS_Util(v1,visited);
}


int main()
{
	int i,j;
	printf("Enter the no. of Vertices:\n");
	scanf("%d",&V);	
	printf("Enter the no. of Edges:\n");
	scanf("%d",&E);
	 
	adj=new int*[V];
	for(i=0;i<V;i++)
	adj[i]=new int[V];
	
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
	
	printf("\n\nDepth First Search   :");
	DFS();
	
	return 0;
}
