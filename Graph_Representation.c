#include<stdio.h>

int main()
{
    int V,E,i,j,v1,v2;
    int **inc,**adj;
    
    printf("Enter the no. of Vertices:\n");
	scanf("%d",&V);	
	printf("Enter the no. of Edges:\n");
	scanf("%d",&E);
	
	adj=(int**)malloc(sizeof(int*)*V);
	for(i=0;i<V;i++)
	adj[i]=(int*)malloc(sizeof(int)*V);
	
	inc=(int**)malloc(sizeof(int*)*V);
	for(i=0;i<V;i++)
	inc[i]=(int*)malloc(sizeof(int)*E);
	
	
	for(i=0;i<V;i++)
	 for(j=0;j<V;j++)
	   adj[i][j]=0;
	   
	for(i=0;i<V;i++)
	 for(j=0;j<E;j++)
	   inc[i][j]=0;
	   
	for(i=0;i<E;i++)
	{
		printf("\nEnter vertices for edge:%d  --->",i+1);
		scanf("%d %d",&v1,&v2);
		
		adj[v1-1][v2-1]=1;
		adj[v2-1][v1-1]=1;
		
		inc[v1-1][i]=1;
		inc[v2-1][i]=1;
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
	
	printf("\n\nIncidence Matrix :");
	for(i=0;i<V;i++)
	{
		printf("\n");
		for(j=0;j<E;j++)
		{
			printf("%d ",inc[i][j]);
		}
	}
	
	return 0;
} 
