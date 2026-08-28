#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <string.h> 
struct infixpriority 
{ 
char ope; 
int pri; 
}; 
struct stackpriority 
{ 
char ope; 
int pri; 
}; 
struct infixpriority ip[]={{'*',2},{'/',2},{'+',1},{'-',1},{'(',3},{')',0},{'#',0}}; 
struct stackpriority sp[]={{'*',2},{'/',2},{'+',1},{'-',1},{'(',0},{')',0},{'#',0}}; 
void main() 
{ 
int i,k,n,top=-1,j=0,ipc,spc; 
char stack[50],c,infixex[20],postfix[20],ch; 
printf("Enter the infix expression\n"); 
scanf("%s",infixex); 
n=strlen(infixex); 
infixex[n]='#'; 
top=top+1; 
stack[top]='#'; 
for(k=0;k<=n;k++) 
{ 
ch=infixex[k]; 
if(ch==')') 
{ 
c=stack[top]; 
top=top-1; 
 
while(c!='(') 
{ 
    postfix[j]=c; 
    j=j+1; 
    c=stack[top]; 
    top=top-1; 
} 
} 
else if(ch=='#') 
{ 
c=stack[top]; 
top=top-1; 
while(c!='#') 
{ 
    postfix[j]=c; 
    j=j+1; 
    c=stack[top]; 
    top=top-1; 
} 
} 
else if(ch=='*' || ch=='/' || ch=='+' || ch=='-' ||ch=='(') 
{ 
    c=stack[top]; 
    top=top-1; 
    for(i=0;i<7;i++) 
    { 
    if(ch==ip[i].ope) 
      ipc=ip[i].pri; 
    } 
    for(i=0;i<7;i++) 
    {  n   
 
    if(c==sp[i].ope) 
      spc=sp[i].pri; 
    } 
    while(spc>=ipc) 
    { 
    postfix[j]=c; 
    j=j+1; 
    c=stack[top]; 
    top=top-1; 
    for(i=0;i<7;i++) 
    { 
    if(c==sp[i].ope) 
      spc=sp[i].pri; 
    } 
    } 
    top=top+1; 
    stack[top]=c; 
    top=top+1; 
    stack[top]=ch; 
} 
else 
 { 
     postfix[j]=ch; 
     j=j+1; 
 } 
} 
postfix[j]='\0'; 
printf("The resultant postfix expression is %s\n",postfix); 
getch(); 
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
9
Enter the element after which new to be inserted
5
Before insertion
5->NULL
After insertion
5->9->NULL

1.Insertion,2.Deletion,3.Find,4.Find previous,5.Print,6.Exit
Enter the choice for operation
1
Enter the element to be inserted
6
Enter the element after which new to be inserted
9
Before insertion
5->9->NULL
After insertion
5->9->6->NULL

1.Insertion,2.Deletion,3.Find,4.Find previous,5.Print,6.Exit
Enter the choice for operation
2
Enter the element to be deleted
9
Before deletion
5->9->6->NULL
After deletion
5->6->NULL

1.Insertion,2.Deletion,3.Find,4.Find previous,5.Print,6.Exit
Enter the choice for operation
5
The elements in the linked list are
5->6->NULL

1.Insertion,2.Deletion,3.Find,4.Find previous,5.Print,6.Exit
Enter the choice for operation


