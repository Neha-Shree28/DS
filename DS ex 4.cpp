#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
struct cnode 
{ 
int data; 
struct cnode *next; 
}; 
void insertion(struct cnode *,int,int); 
void deletion(struct cnode *,int); 
struct cnode *find(struct cnode *,int); 
struct cnode *findprevious(struct cnode *,int); 
void print(struct cnode *); 
void main() 
{ 
struct cnode *head,*p; 
int ch,x,m; 
//Creation of header node 
head=(struct cnode*)malloc(sizeof(struct cnode)); 
head->data=-1; 
head->next=head; 
while(1) 
{ 
 printf("\n1.Insertion  2.Deletion  3.find  4.findprevious  5.print  6.exit\n"); 
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
void insertion(struct cnode *head,int x,int m) 
{ 
 struct cnode *newnode,*p; 
 newnode=(struct cnode*)malloc(sizeof(struct cnode)); 
 newnode->data=x; 
if(m==-1) 
{ 
 newnode->next=head->next; 
 head->next=newnode; 
} 
else 
{ 
 p=head->next; 
while(p!=head) 
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
void deletion(struct cnode *head,int x) 
{ 
 struct cnode *p,*pre; 
 pre=head; 
 p=head->next; 
while(p!=head) 
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
struct cnode *find(struct cnode *head, int x) 
{ 
struct cnode *p; 
 p=head->next; 
while(p!=head) 
{ 
if(x==p->data) 
return(p); 
else 
 p=p->next; 
} 
} 
struct cnode *findprevious(struct cnode *head, int x) 
{ 
  struct cnode *p,*pre; 
  pre=head; 
  p=head->next; 
while(p!=head) 
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
void print(struct cnode *head) 
{ 
  struct cnode *p; 
  p=head->next; 
while(p!=head) 
{ 
  printf("%d-->",p->data); 
  p=p->next; 
} 
}

OUTPUT :

1.Insertion,2.Deletion,3.Find,4.Find previous,5.Print,6.Exit
Enter the choice for operation
1
Enter the element to be inserted
5
Enter the element after which new to be inserted
-1
Before insertion
NULL
After insertion
5->NULL

1.Insertion,2.Deletion,3.Find,4.Find previous,5.Print,6.Exit
Enter the choice for operation
1
Enter the element to be inserted
8
Enter the element after which new to be inserted
5
Before insertion
5->NULL
After insertion
5->8->NULL

1.Insertion,2.Deletion,3.Find,4.Find previous,5.Print,6.Exit
Enter the choice for operation
4
Enter the element to be searched
8
The previous snode address of the element is 0000000000C41470

1.Insertion,2.Deletion,3.Find,4.Find previous,5.Print,6.Exit
Enter the choice for operation
5
The elements in the linked list are
5->8->NULL

1.Insertion,2.Deletion,3.Find,4.Find previous,5.Print,6.Exit
Enter the choice for operation

