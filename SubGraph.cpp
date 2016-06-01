#include<iostream>
using namespace std;

	int V1,V2,E1,E2;
	int **g1,**g2;
	
int main()
{
    int i,j,v1,v2;
	
	cout<<endl<<"\nEnter Vertices and Edges for the graph-1 :";
	cin>>V1>>E1;
	cout<<endl<<"\nEnter Vertices and Edges for the graph-2 :";
	cin>>V2>>E2;
	
	g1=new int*[V1];
	for(i=0;i<V1;i++)
	g1[i]=new int[V1];
	
	g2=new int*[V2];
	for(i=0;i<V2;i++)
	g2[i]=new int[V2];
	
	for(i=0;i<V1;i++)
	 for(j=0;j<V1;j++)
	  g1[i][j]=0;
	
	for(i=0;i<V2;i++)
	 for(j=0;j<V2;j++)
	   g2[i][j]=0;
	
	cout<<"\nEnter Graph-1 Details :"<<endl;
	for(i=0;i<E1;i++)
	{
		cout<<"Enter vertices for edge :"<<i+1<<" ";
		cin>>v1>>v2;
		g1[v1-1][v2-1]=1;
		g1[v2-1][v1-1]=1;
	}
	
	cout<<"\nEnter Graph-2 Details :"<<endl;
	for(i=0;i<E2;i++)
	{
		cout<<"Enter vertices for edge :"<<i+1<<" ";
		cin>>v1>>v2;
		g2[v1-1][v2-1]=1;
		g2[v2-1][v1-1]=1;
	}
	
	int k,l,found;
	for(i=0;i<=V1-V2;i++)
	{
		for(j=0;j<=V1-V2;j++)
		{
			k=0,l=0,found=1;
			for(k=0;k<V2;k++)
			{
				for(l=0;l<V2;l++)
				{
					 if(g1[i+k][j+l]!=g2[k][l])
					 {
					 	found=0;
					 	break;
					 }
				}
				if(found==0)
				break;
			}
			if(k==V2&&l==V2)
			{
				found=1;
				break;
			}
		}
		if(found==1)
		break;
	}
	if(found==1)
	cout<<"\n\nGrapg g2 is subgraph of another graph g1"<<endl;
	else
	cout<<"\n\nGrapg g2 is not subgraph of another graph g1"<<endl;
	
	return 0;
}
