#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void quicksort(int [],int,int);
int partition(int [],int,int);
void display(int [],int);
int main()
{
	int a[20],n,i;
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	printf("Enter the elements of an array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n Elements of the array before sorting\n");
	display(a,n);
	quicksort(a,0,n-1);
	printf("\n Elements of the array after sorting\n");
	display(a,n);
	getch();
}
void quicksort(int a[],int l,int r)
{
	int p;
	if(l<r)
	{
		p=partition(a,l,r);
		quicksort(a,l,p-1);
		quicksort(a,p+1,r);
	}
}
int partition(int a[],int l,int r)
{
	int i,j,pivot,t;
	pivot=a[l];
	i=l+1;
	j=r;
while(i<j)
{
	while(a[i]<pivot)
		i++;
	while(a[j]>pivot)
		j--;
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	t=a[i];
	a[i]=a[j];

	a[j]=t;
	t=a[l];
	a[l]=a[j];
	a[j]=t;
	return j;
}
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
