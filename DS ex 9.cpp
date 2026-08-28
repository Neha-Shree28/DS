#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int h[20];

int n=0;
void insert(int);
void delete1();
void print();
void main()
{
int ch,x;
while(1)
{
printf("\n1.Insertion, 2.Deletion, 3.print,4.Exit\n");
printf("Enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter the element to be inserted");
scanf("%d",&x);
printf("Before Insertion\n");
print();
insert(x);
printf("After Insertion\n");
print();
break;
case 2: printf("Before Deletion\n");
print();
delete1();
printf("After Deletion\n");
print();
break;
case 3: printf("The elements of the heap\n");
print();
case 4: exit(0);

}
}
getch();
}
void insert(int x)
{
int i;
n=n+1;
for(i=n;i>1;i=i/2)
{
if(h[i/2]<x)
break;
else
h[i]=h[i/2];
}
h[i]=x;
}
void delete1()
{
int i,c,del,x;
del=h[1];
x=h[n];
n=n-1;
for(i=1;i*2<=n;i=c)
{
c=2*i;
if(c<n && h[c]>h[c+1])
c=c+1;
if(x<h[c])
break;
else
h[i]=h[c];
}
h[i]=x;
printf("\nThe deleted element is %d\n",del);
}
void print()
{
int i;
for(i=1;i<=n;i++)
{
printf("%d\t",h[i]);
}
}

OUTPUT :
1.Insertion, 2.Deletion, 3.print,4.Exit
Enter the choice
1
Enter the element to be inserted10
Before Insertion
After Insertion
10
1.Insertion, 2.Deletion, 3.print,4.Exit
Enter the choice
1
Enter the element to be inserted5
Before Insertion
10 After Insertion
5 10
1.Insertion, 2.Deletion, 3.print,4.Exit
Enter the choice
2

74

Before Deletion
5 10
The deleted element is 5
After Deletion
10
1.Insertion, 2.Deletion, 3.print,4.Exit
Enter the choice
2
Before Deletion
10
The deleted element is 10
After Deletion

1.Insertion, 2.Deletion, 3.print,4.Exit
Enter the choice
1
Enter the element to be inserted15
Before Insertion
After Insertion
15
1.Insertion, 2.Deletion, 3.print,4.Exit
Enter the choice
1
Enter the element to be inserted20
Before Insertion
15 After Insertion
15 20
1.Insertion, 2.Deletion, 3.print,4.Exit
Enter the choice
1
Enter the element to be inserted12

75

Before Insertion
15 20 After Insertion
12 20 15
1.Insertion, 2.Deletion, 3.print,4.Exit
Enter the choice
2
Before Deletion
12 20 15
The deleted element is 12
After Deletion
15 20
1.Insertion, 2.Deletion, 3.print,4.Exit
Enter the choice
