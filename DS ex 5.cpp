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

