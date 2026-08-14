#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int a[5],n;
void insertion(int,int);
int deletion(int);
int search(int);
void display();

int main()
{
	int i,ch,x,pos,del;
	printf("Enter the number of elements in the list\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element for array : ");
		scanf("%d",&a[i]);
	}

while(1)
{
	printf("\n1.Insertion, 2.Deletion, 3.Search, 4. Display, 5.Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
switch(ch)
{
	case 1: printf("Enter the element to be inserted\n");
	scanf("%d",&x);
	printf("Enter the position for insertion\n");
	scanf("%d",&pos);
	insertion(x,pos);
	display();
	break;
	case 2: printf("Enter the position of the element to be deleted\n");
	scanf("%d",&pos);
	del=deletion(pos);
	printf("The deleted value is %d\n",del);
	display();
	break;

	case 3: printf("Enter the element to be searched\n");
	scanf("%d",&x);
	pos=search(x);
	if (pos==-1)
		printf("The element is not present the in the list\n");
	else
		printf("The element is present at the %d place of the list\n",pos);
	break;
	case 4: 
		display();
		break;
	case 5: 
		exit(0);
		break;

}
}
	getch();
}
void insertion(int x,int pos)
{
	int i;
	if(n==5)
	{
		printf("List is full,Cannot insert");
		return;
	}
	else
	{
		i=n-1;
		while(i>=pos)
	{
		a[i+1]=a[i];

		i--;
	}
	a[pos]=x;
	n=n+1;
}
}
int deletion(int pos)
	{
	int i,del;
	if(n==0)
	{
		printf("List is empty,Cannot delete");
		return -1;
	}
	else
	{
		del=a[pos];
		i=pos+1;
	while(i<=n-1)
	{
		a[i-1]=a[i];
		i++;
	}
	n=n-1;
	return del;
}
}
int search(int x)
{
	int i;
	for (i=0;i<=n-1;i++)
	{
	if(x==a[i])
	return i;
	}
	return -1;
}
void display()
{
	int i;
	printf("\nThe elements of the list are\n");
	for(i=0;i<n;i++)
	{
	printf("%d ",a[i]);
	}
}
