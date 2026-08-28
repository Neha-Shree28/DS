#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
int cqueue[5]={-1,-1,-1,-1,-1}; 
int rear=-1; 
int front=0; 
void enqueue(int); 
void dequeue(); 
void print(); 
int main() 
{ 
int ch,x; 
while(1) 
{ 
printf("\n1.enqueue\t 2.dequeue\t 3.Printqueue\t 4.Exit\n"); 
 
printf("Enter your Choice\n"); 
scanf("%d",&ch); 
switch(ch) 
{ 
case 1:printf("enter the element to be inserted\n"); 
       scanf("%d",&x); 
       printf("Before Enqueue-"); 
       print(); 
       enqueue(x); 
       break; 
case 2:printf("Before dequeue-"); 
       print(); 
       dequeue(); 
       break; 
case 3:print(); 
       break; 
case 4:exit(0); 
       break; 
} 
} 
getch(); 
} 
void enqueue(int x) 
{ 
rear=(rear+1)%5; 
if(rear==front && cqueue[front] != -1) 
printf("queue is full"); 
else 
{ 
cqueue[rear]=x; 
printf("\nAfter enqueue- rear= %d\n",rear); 
print(); 
} 
} 
void dequeue() 
{ 
int del; 
if(cqueue[front] == -1) 
{ 
printf("circular queue is empty"); 
} 
else 
{ 
del=cqueue[front]; 
cqueue[front]=-1; 
front=(front+1)%5; 
printf("\nThe deleted item is %d\n",del); 
printf("After dequeue front=%d\n",front); 
print(); 
} 
} 
void print() 
{ 
int i; 
printf("Queue Contents are\n"); 
i=front; 
while(1) 
{ 
if(cqueue[i]==-1) 
{ 
printf("Empty"); 
break; 
 
} 
else if(i==rear) 
{ 
printf("%d\t",cqueue[i]); 
break; 
} 
else 
{ 
printf("%d\t",cqueue[i]); 
i=(i+1)%5; 
} 
} 
} 
