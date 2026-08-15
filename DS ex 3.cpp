#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
struct dnode 
{ 
  int data; 
  struct dnode *next,*prev; 
}; 

void insertion(struct dnode *,int,int); 
void deletion(struct dnode *,int); 
struct dnode *find(struct dnode *,int); 
void print(struct dnode *); 
int main() 
{ 
  struct dnode *head,*p,*q; 
  int ch,x,m;  
  head=(struct dnode*)malloc(sizeof(struct dnode)); 
  head->data=-1; 
  head->prev=NULL; 
  head->next=NULL; 
  while(1) 
  { 
      printf("\n1.Insertion  2.Deletion  3.find  4.print  5.exit\n"); 
      printf("Enter the choice for operations\n"); 
      scanf("%d",&ch); 
switch(ch) 
{ 
    case 1: printf("Enter the element to be inserted\n"); 
    scanf("%d",&x); 
    printf("Enter the element after which new to be inserted\n"); 
    scanf("%d",&m); 
    printf("\nBefore Insertion\n"); 
    print(head); 
    insertion(head,x,m); 
    printf("\nAfter Insertion\n"); 
    print(head); 
    break; 
    case 2:printf("Enter the element to be deleted\n"); 
       scanf("%d",&x); 
       printf("\nBefore Deletion\n"); 
       print(head); 
       deletion(head,x); 
       printf("\nAfter Deletion\n"); 
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
case 4:printf("The elements in the linked list are\n"); 
       print(head); 
       break; 
case 5:exit(0); 
       break; 
  } 
} 
getch(); 
} 
void insertion(struct dnode *head,int x,int m) 
{ 
  struct dnode *newnode,*p,*q; 
  newnode=(struct dnode*)malloc(sizeof(struct dnode)); 
  newnode->data=x; 
  if(m==-1) 
  { 
      newnode->next=head->next; 
      newnode->prev=head; 
      head->next=newnode; 
  } 
  else 
  { 
      p=head->next; 
      while(p!=NULL) 
      { 
        if(m==p->data) 
        { 
            q=p->next; 
            if(q==NULL) 
            { 
                newnode->next=NULL; 
                newnode->prev=p; 
                p->next=newnode;  
            } 
            else 
            { 
                  newnode->next=q; 
                  newnode->prev=p; 
                  q->prev=newnode; 
                  p->next=newnode; 
              } 
              return; 
          } 
          else 
            p=p->next; 
          } 
        } 
} 
void deletion(struct dnode *head,int x) 
{ 
    struct dnode *p,*pr,*ne; 
    p=head->next; 
    while(p!=NULL) 
    { 
      if(x==p->data) 
      { 
          pr=p->prev; 
          if(p->next==NULL) 
          { 
              pr->next=NULL;  
          } 
          else 
          { 
              pr=p->prev; 
              ne=p->next; 
              pr->next=ne; 
              ne->prev=pr; 
            } 
            free(p); 
            return; 
          } 
          else 
          { 
              p=p->next; 
          } 
      } 
} 
struct dnode *find(struct dnode *head, int x) 
{ 
    struct dnode *p; 
    p=head->next; 
    while(p!=NULL) 
    { 
        if(x==p->data) 
        return(p); 
        else 
        p=p->next; 
    } 
} 
void print(struct dnode *head) 
{ 
      struct dnode *p; 
      p=head; 
      while(p!=NULL) 
      { 
          printf("%d-->",p->data); 
          p=p->next; 
      } 
}

OUTPUT

1.Insertion  2.Deletion  3.find  4.print  5.exit
Enter the choice for operations
1
Enter the element to be inserted
5
Enter the element after which new to be inserted
-1

Before Insertion
-1-->
After Insertion
-1-->5-->
1.Insertion  2.Deletion  3.find  4.print  5.exit
Enter the choice for operations
1
Enter the element to be inserted
6
Enter the element after which new to be inserted
5

Before Insertion
-1-->5-->
After Insertion
-1-->5-->6-->
1.Insertion  2.Deletion  3.find  4.print  5.exit
Enter the choice for operations
2
Enter the element to be deleted
5

Before Deletion
-1-->5-->6-->
After Deletion
-1-->6-->
1.Insertion  2.Deletion  3.find  4.print  5.exit
Enter the choice for operations
4
The elements in the linked list are
-1-->6-->
1.Insertion  2.Deletion  3.find  4.print  5.exit
Enter the choice for operations

