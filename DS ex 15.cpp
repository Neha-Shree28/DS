#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
int g[10][10],known[10],d[10],p[10];
int n,i,j,flag,lowpos,small;
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
known[i]=0;
d[i]=1000;
p[i]=-1;
}
d[1]=0;
//Processing the vertices in stages
while(1)
{
flag=0;
for(i=1;i<=n;i++)
{
if(known[i]==0)
flag=1;
}
if(flag==0)
break;
small=1000;
for(i=1;i<=n;i++)
{
if(known[i]!=1)
{
if(d[i]<small)
{

lowpos=i;
small=d[i];
}
}
}
known[lowpos]=1;
for(i=1;i<=n;i++)
{
if(known[i]!=1)
{
if(g[lowpos][i]!=0)
{
if(d[lowpos]+g[lowpos][i]<d[i])
{
d[i]=d[lowpos]+g[lowpos][i];
p[i]=lowpos;
}
}
}
}
printf("\nV\tKnown\tD\tP\n");
for(i=1;i<=n;i++)
{
printf("%d\t%d\t%d\t%d\n",i,known[i],d[i],p[i]);
}
}
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

V Known D P
1 1 0 -1
2 0 5 1
3 0 3 1
4 0 1000 -1

V Known D P
1 1 0 -1
2 0 4 3
3 1 3 1
4 0 5 3

V Known D P
1 1 0 -1
2 1 4 3
3 1 3 1
4 0 5 3

V Known D P
1 1 0 -1
2 1 4 3
3 1 3 1
4 1 5 3
