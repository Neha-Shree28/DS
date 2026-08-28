#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int h[20],a[20];
int n=0,m;
void insert(int);
int delete1();
void print();
void print1();
void main()
{
int i,x;
printf("Enter the number of elements into the array\n");
scanf("%d",&m);
for(i=0;i<m;i++)
{
printf("Enter the element of the array\n");
scanf("%d",&x);
insert(x);
}
printf("Array Elements after Heapify\n");
  
print();
for(i=0;i<m;i++)
{
a[m-i-1]=delete1();
}
printf("\nArray Elements after Heapsort\n");
print1();
getch();
}
void insert(int x)
{
int i;
n=n+1;
for(i=n;i>1;i=i/2)
{
if(h[i/2]>x)
break;
else
h[i]=h[i/2];
}
h[i]=x;
}
int delete1()
{
int i,c,del,x;
del=h[1];
x=h[n];
n=n-1;
for(i=1;i*2<=n;i=c)
{
c=2*i;

if(c<n && h[c]<h[c+1])
c=c+1;
if(x>h[c])
break;
else
h[i]=h[c];
}
h[i]=x;
return del;
}
void print()
{
int i;
for(i=1;i<=m;i++)
{
printf("%d\t",h[i]);
}
}
void print1()
{
int i;
for(i=0;i<m;i++)
{
printf("%d\t",a[i]);
}
}

OUTPUT: 
Enter the number of elements into the array
5
Enter the element of the array
8
Enter the element of the array
10
Enter the element of the array
34
Enter the element of the array
25
Enter the element of the array
19
Array Elements after Heapify
34 25 10 8 19
Array Elements after Heapsort
8 10 19 25 34
