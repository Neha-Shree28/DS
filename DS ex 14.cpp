#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
int g[10][10],MST[10];
int n,i,j,k,mincost,cost=0,u,v;
printf("Enter the number of vertices in the graph\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("Enter the edge weight between vertex %d and vetex %d\t", i,j);
scanf("%d",&g[i][j]);
}

}
//Initialization
for(i=1;i<=n;i++)
{
MST[i]=0;
}
MST[1]=1;
//Processing the vertices in stages
for(k=1;k<=n-1;k++)
{
mincost=9999;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(g[i][j] && ((MST[i] && !MST[j]) || (!MST[i] && MST[j])))
{
if(g[i][j]<mincost)
{
mincost=g[i][j];
u=i;
v=j;
}
}
}
}
printf("\n The added edge is %d--%d, cost=%d",u,v,mincost);
MST[u]=1;
MST[v]=1;
cost=cost+mincost;
}

printf("\n The cost of MST is = %d",cost);
getch();
}

OUTPUT:
Enter the number of vertices in the graph
4
Enter the edge weight between vertex 1 and vetex 1 0
Enter the edge weight between vertex 1 and vetex 2 5
Enter the edge weight between vertex 1 and vetex 3 3
Enter the edge weight between vertex 1 and vetex 4 0
Enter the edge weight between vertex 2 and vetex 1 5
Enter the edge weight between vertex 2 and vetex 2 0
Enter the edge weight between vertex 2 and vetex 3 1
Enter the edge weight between vertex 2 and vetex 4 4
Enter the edge weight between vertex 3 and vetex 1 3
Enter the edge weight between vertex 3 and vetex 2 1
Enter the edge weight between vertex 3 and vetex 3 0
Enter the edge weight between vertex 3 and vetex 4 2
Enter the edge weight between vertex 4 and vetex 1 0
Enter the edge weight between vertex 4 and vetex 2 4
Enter the edge weight between vertex 4 and vetex 3 2
Enter the edge weight between vertex 4 and vetex 4 0

The added edge is 1--3, cost=3
The added edge is 2--3, cost=1
The added edge is 3--4, cost=2
The cost of MST is = 6
