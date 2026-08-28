#include <stdio.h>
#include <conio.h>

49

#include <stdlib.h>
struct bstnode
{
int data;
struct bstnode *left;
struct bstnode *right;
};
struct bstnode *insert(struct bstnode *,int);
struct bstnode *delete1(struct bstnode *,int);
void find(struct bstnode *,int);
struct bstnode *findmin(struct bstnode *);
struct bstnode *findmax(struct bstnode *);
void printinorder(struct bstnode *);
void printpreorder(struct bstnode *);
void printpostorder(struct bstnode *);
void main()
{
int ch,x;
struct bstnode *t,*t1;
printf("enter the value of the root node\n");
t=(struct bstnode *)malloc(sizeof(struct bstnode));
scanf("%d",&t->data);
t->left=NULL;
t->right=NULL;
while(1)
{
printf("\n1.Insertion, 2.Deletion 3.find, 4.findmin 5.findmax 6.print, 7.exit\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{

case 1:printf("enter the data to be inserted\n");
	scanf("%d",&x);
	t=insert(t,x);
	printf("\nInorder Traversal is\n");
	printinorder(t);
	printf("\nPreorder Traversal is\n");
	printpreorder(t);
	printf("\nPostorder Traversal is\n");
	printpostorder(t);
	break;
case 2:printf("enter the data to be removed\n");
	scanf("%d",&x);
	t=delete1(t,x);
	printf("\nInorder Traversal is\n");
	printinorder(t);
	printf("\nPreorder Traversal is\n");
	printpreorder(t);
	printf("\nPostorder Traversal is\n");
	printpostorder(t);
	break;
case 3:printf("enter the data to be searched\n");
	scanf("%d",&x);
	find(t,x);
	break;
case 4:t1=findmin(t);
	printf("The min value is %d\n",t1->data);
	break;
case 5:t1=findmax(t);
	printf("The max value is %d\n",t1->data);
	break;
case 6:printf("\nInorder Traversal is\n");

	printinorder(t);
	printf("\nPreorder Traversal is\n");
	printpreorder(t);
	printf("\nPostorder Traversal is\n");
	printpostorder(t);
	break;
case 7:exit(0);
}
}
getch();
}
struct bstnode *insert(struct bstnode *t,int x)
{
if(t==NULL)
{
t=(struct bstnode *)malloc(sizeof(struct bstnode));
t->data=x;
t->left=NULL;
t->right=NULL;
}
else if(x<t->data)
t->left=insert(t->left,x);
else if(x>t->data)
t->right=insert(t->right,x);
return t;
}
struct bstnode *delete1(struct bstnode *t, int x)
{
struct bstnode *tmp;

if(t == NULL) {

printf("The element is not present in the tree\n");
}
else if(x < t->data) {
t->left = delete1(t->left, x);
}
else if(x > t->data) {
t->right = delete1(t->right, x);
}
else {
// Node with two children
if(t->left != NULL && t->right != NULL) {
tmp = findmin(t->right);
t->data = tmp->data;
t->right = delete1(t->right, tmp->data);
}
// Node with one child or zero children (Leaf)
else {
tmp = t;

if(t->left == NULL) {
t = t->right;
}
else if(t->right == NULL) {
t = t->left;
}

free(tmp);
}
}
return t;
}

void find(struct bstnode *t,int x)
{
if(t==NULL)
{
printf("The element is not present in the tree\n");
return;
}
if(x<t->data)
find(t->left,x);
if(x>t->data)
find(t->right,x);
else
printf("The element is present\n");
}
struct bstnode *findmin(struct bstnode *t)
{
while(t->left!=NULL)
{
t=t->left;
}
return t;
}
struct bstnode *findmax(struct bstnode *t)
{
while(t->right!=NULL)
{
t=t->right;
}
return t;
}
void printinorder(struct bstnode *t)
 
{
if(t==NULL)
return;
else
{
printinorder(t->left);
printf("\t%d",t->data);
printinorder(t->right);
}
}
void printpreorder(struct bstnode *t)
{
if(t==NULL)
return;
else
{
printf("\t%d",t->data);
printpreorder(t->left);
printpreorder(t->right);
}
}
void printpostorder(struct bstnode *t)
{
if(t==NULL)
return;
else
{
printpostorder(t->left);
printpostorder(t->right);
printf("\t%d",t->data);
}
}

OUTPUT:
enter the value of the root node
10
1.Insertion, 2.Deletion 3.find, 4.findmin 5.findmax 6.print, 7.exit
enter your choice
1
enter the data to be inserted
20
Inorder Traversal is
10 20
Preorder Traversal is
10 20
Postorder Traversal is
20 10
1.Insertion, 2.Deletion 3.find, 4.findmin 5.findmax 6.print, 7.exit
enter your choice
1
enter the data to be inserted
5
Inorder Traversal is
5 10 20
Preorder Traversal is
10 5 20
Postorder Traversal is
5 20 10
1.Insertion, 2.Deletion 3.find, 4.findmin 5.findmax 6.print, 7.exit
enter your choice
1
enter the data to be inserted
40

56

Inorder Traversal is
5 10 20 40
Preorder Traversal is
10 5 20 40
Postorder Traversal is
5 40 20 10
1.Insertion, 2.Deletion 3.find, 4.findmin 5.findmax 6.print, 7.exit
enter your choice
2
enter the data to be removed
10
Inorder Traversal is
5 20 40
Preorder Traversal is
20 5 40
Postorder Traversal is
5 40 20
1.Insertion, 2.Deletion 3.find, 4.findmin 5.findmax 6.print, 7.exit
enter your choice
4
The min value is 5
1.Insertion, 2.Deletion 3.find, 4.findmin 5.findmax 6.print, 7.exit
enter your choice
5
The max value is 40
1.Insertion, 2.Deletion 3.find, 4.findmin 5.findmax 6.print, 7.exit
enter your choice
