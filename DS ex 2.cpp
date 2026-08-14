#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct snode
{
	int data;
	struct snode *next;
};
void insertion(struct snode *,int,int);
void deletion(struct snode *,int);
struct snode *find(struct snode *,int);
struct snode *findprevious(struct snode *,int);
void print(struct snode *);
int main()
{
	struct snode *head,*p;
	int ch,x,m;
	head=(struct snode*)malloc(sizeof(struct snode));
	head->data=-1;
	head->next=NULL;
	while(1)
	{
		printf("\n1.Insertion 2.Deletion 3.find 4.findprevious 5.print 6.exit\n");
		printf("Enter the choice for operations\n");
		scanf("%d",&ch);
switch(ch)
{
	case 1: printf("Enter the element to be inserted\n");
	scanf("%d",&x);
	printf("Enter the element after which new to be inserted\n");
	scanf("%d",&m);
	printf("Before Insertion\n");
	print(head);
	insertion(head,x,m);
	printf("After Insertion\n");
	print(head);
	break;
	
	case 2:printf("Enter the element to be deleted\n");
	scanf("%d",&x);
	printf("Before Deletion\n");
	print(head);
	deletion(head,x);
	printf("After Deletion\n");
	print(head);
	break;
	case 3:printf("enter the element to be searched\n");
	scanf("%d",&x);
	p=find(head,x);
	if(p!=NULL)
		printf("The element is present at the address %d\n",p);
	else
		printf("The element is not present\n");
	break;
	case 4:printf("enter the element to be searched\n");
	scanf("%d",&x);
	p=findprevious(head,x);
	if(p!=NULL)
		printf("The previous snode address of the element is %d\n",p);
	else
		printf("The element is not present\n");
	break;
	case 5:printf("The elements in the linked list are\n");
	print(head);
	break;
	case 6:exit(0);
	break;
}
}
	getch();
}
void insertion(struct snode *head,int x,int m)
{
	struct snode *newnode,*p;
	newnode=(struct snode*)malloc(sizeof(struct snode));
	newnode->data=x;
	if(m==-1)
	{
		newnode->next=head->next;
		head->next=newnode;
	}
	else
	{
		p=head->next;
		while(p!=NULL)
		{
		if(m==p->data)
		{	
		newnode->next=p->next;
		p->next=newnode;
		return;
		}
		else
		p=p->next;
}
}
}
void deletion(struct snode *head,int x)
{
	struct snode *p,*pre;
	pre=head;
	p=head->next;
	while(p!=NULL)
	{
	if(x==p->data)
	{
		pre->next=p->next;
		free(p);
		return;
	}
		else
	{
		pre=p;
		p=p->next;
	}
	}
	}
struct snode *find(struct snode *head, int x)
{
	struct snode *p;
	p=head->next;
	while(p!=NULL)
	{
	if(x==p->data)
	return(p);
	else
	p=p->next;
}
}
struct snode *findprevious(struct snode *head, int x)
{
	struct snode *p,*pre;
	pre=head;
	p=head->next;
	while(p!=NULL)
	{
	if(x==p->data)
	return(pre);
	else
	{
		pre=p;
		p=p->next;
	}
}
}
void print(struct snode *head)
{
	struct snode *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d-->",p->data);
		p=p->next;
}
}
