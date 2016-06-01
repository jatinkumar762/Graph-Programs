#include<iostream>
using namespace std;
#include<stdlib.h>

int V1,E1,V2,E2;
int **graph_1,**graph_2;

struct visited
{
	int data;
	int flag;
};
typedef struct visited visited;

visited *visit1,*visit2; 

int isomorphic()
{
	int i,j,flag;
	if(V1!=V2)
	{
		return 0;
	}
	else
	if(E1!=E2)
	{
		return 0;
	}
	else
	{
        for(i=0;i<V1;i++)
		{
			flag=0;
			for(j=0;j<V2;j++)
			{
		       if(visit2[j].flag==0)
			   {
			   	   if(visit2[j].data==visit1[i].data)
			   	   {
			   	   	  visit2[j].flag=visit1[i].flag=1;
			   	   	  flag=1;
			   	   	  break;
			   	   }
			   }	   	
			}
			if(!flag)
			break;
		}      
		if(i<V1)
		return 0;
	}
	return 1;
}

int main()
{
    int i,j,v1,v2;
	
	cout<<"\nEnter no. of vertex and edges for graph 1:";
	cin>>V1>>E1;
	
	cout<<"\nEnter no. of vertex and edges for graph 2:";
	cin>>V2>>E2;
	
	graph_1=(int**)malloc(sizeof(int*)*V1);
	for(i=0;i<V1;i++)
	graph_1[i]=(int*)malloc(sizeof(int)*V1);
	
    graph_2=(int**)malloc(sizeof(int*)*V2);
	for(i=0;i<V2;i++)
	graph_2[i]=(int*)malloc(sizeof(int)*V2);
	
	visit1=(visited*)malloc(sizeof(visited)*V1);
	visit2=(visited*)malloc(sizeof(visited)*V2);
	
	for(i=0;i<V1;i++)
		for(j=0;j<V1;j++)
			graph_1[i][j]=0;

	for(i=0;i<V2;i++)
		for(j=0;j<V2;j++)
			graph_2[i][j]=0;
	
	for(i=0;i<V1;i++)
	{
		visit1[i].data=0;
		visit1[i].flag=0;
	}
	for(i=0;i<V2;i++)
	{
		visit2[i].data=0;
		visit2[i].flag=0;
	}
	
	cout<<endl<<"Graph-1 Details :";
	for(i=0;i<E1;i++)
	{
		cout<<"\nEnter vertices for edge "<<i+1<<" :";
		cin>>v1>>v2;
		graph_1[v1-1][v2-1]=1;
		graph_1[v2-1][v1-1]=1;
		visit1[v1-1].data++;
		visit1[v2-1].data++;
	}	
	cout<<endl<<"Graph-2 Details :";
	for(i=0;i<E2;i++)
	{
		cout<<"\nEnter vertices for edge "<<i+1<<" :";
		cin>>v1>>v2;
		graph_2[v1-1][v2-1]=1;
		graph_2[v2-1][v1-1]=1;
		visit2[v1-1].data++;
		visit2[v2-1].data++;
	}
	
		
	if(isomorphic())
	{
		cout<<"\n\nBoth Graphs are Isomorphic"<<endl;
	}
	else
	{
		cout<<"\n\nBoth Graphs are not Isomorphic"<<endl;
	}
	
	return 0;
}
