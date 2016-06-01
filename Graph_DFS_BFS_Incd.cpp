#include<stdio.h>
#include<list>
#include<stdlib.h>
#include<iostream>
using namespace std;

int V,E,i,j,v1,v2;
int **inc;

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
		
		for(int i=0;i<E;i++)
		{
			if(inc[s][i]==1)
			{
				for(int j=0;j<V;j++)
				{
					if(inc[j][i]==1)
					{
						if(!visited[j])
						{
							visited[j]=true;
							queue.push_back(j);
						}
				    }
			    }
			}
		}
	}
		
}

void DFS_Util(int s,bool *visited)
{
	visited[s]=true;
	cout<<(s+1)<<" ";
	
	for(i=0;i<E;i++) 
	{
		if(inc[s][i]==1)
		{
			for(int j=0;j<V;j++)
			{
			    if(inc[j][i]==1)
			    {
			       if(!visited[j])
			       {
				     DFS_Util(j,visited);
			       }
			    }
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
	
	inc=(int**)malloc(sizeof(int*)*V);
	for(i=0;i<V;i++)
	inc[i]=(int*)malloc(sizeof(int)*E);
	
	   
	for(i=0;i<V;i++)
	 for(j=0;j<E;j++)
	   inc[i][j]=0; 
	   
	for(i=0;i<E;i++)
	{
		printf("\nEnter vertices for edge:%d  --->",i+1);
		scanf("%d %d",&v1,&v2);
		
		inc[v1-1][i]=1;
		inc[v2-1][i]=1;
	}

	
	printf("\n\nIncidence Matrix :");
	for(i=0;i<V;i++)
	{
		printf("\n");
		for(j=0;j<E;j++)
		{
			printf("%d ",inc[i][j]);
		}
	}

    printf("\n\nBreadth First Search :");
    BFS(2);
    
    printf("\n\nDepth First Search  :");
    DFS();
    
	return 0;
} 
