#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main()
{
int hashtable[10],i,j,k,x,flag;
//Initialization of Hash table
for(i=0;i<10;i++)
hashtable[i]=0;
printf("Enter the numbers to be stored in the hashtable, enter -1 to terminate\n");
while(1)
{
printf("enter the number to be entered into the hashtable\n");
scanf("%d",&x);
if(x==-1)
break;
flag=0;
i=x%10;
k=i;
j=1;
while(flag==0)
{
if(hashtable[i]==0)
{
hashtable[i]=x;
flag=1;
}
else
{
i=(k+(j*j))%10;
j=j+1;
}
}
}
printf("The elements of the hashtable are\n");
for(i=0;i<10;i++)
printf("%d\t",hashtable[i]);
getch();
}

OUTPUT:
Enter the numbers to be stored in the hashtable, enter -1 to terminate
enter the number to be entered into the hashtable
10
enter the number to be entered into the hashtable
11
enter the number to be entered into the hashtable
14
enter the number to be entered into the hashtable
20
enter the number to be entered into the hashtable
-1
The elements of the hashtable are
10 11 0 0 14 0 0 0 0 20
