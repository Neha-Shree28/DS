#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int graph[5][5], visited[5];
int queue[10];
int front = 0, rear = -1;
int n;
void BFS(int);

void main()
{
int i, j, start;
printf("Enter number of vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for(i = 0; i < n; i++)
for(j = 0; j < n; j++)
scanf("%d", &graph[i][j]);
for(i = 0; i < n; i++)
visited[i] = 0;
printf("Enter starting vertex: ");
scanf("%d", &start);
printf("BFS Traversal: ");
// Traverse the starting component
BFS(start);
// Traverse remaining disconnected components
for(i = 0; i < n; i++)
{
if(visited[i] == 0)
BFS(i);
}
getch();
}
// BFS Function
void BFS(int start)
{
int i, vertex;
visited[start] = 1;
rear++;
queue[rear] = start;

while(rear>=front)
{
vertex = queue[front];
front++;
printf("%d ", vertex);
for(i = 0; i < n; i++)
{
if(graph[vertex][i] == 1 && visited[i] == 0)
{
visited[i] = 1;
rear++;
queue[rear] = i;
}
}
}
}

OUTPUT:
Enter number of vertices: 4
Enter adjacency matrix:
0
1
0
1
1
0
1
1
0
1
0
0

100

1
1
0
0
Enter starting vertex: 0
BFS Traversal: 0 1 3 2
