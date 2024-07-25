#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node*left;
struct node *right;
}*temp,*p,*root=NULL;

struct node*newnode(int data){
temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
}

struct node*creation(struct node*root,int key){
int n,i,data;

if (root==NULL){
    return newnode(key);
}
else if(key<root->data){
    root->left=creation(root->left,key);
}
else{
    root->right=creation(root->right,key);
}
return root;
}

void xtraverse(struct node*root){
	if(root ==NULL)	return ;
	else {
		printf("%d\t",root->data);
		xtraverse(root->right);
		printf("%d\t",root->data);
		xtraverse(root->left);
	}
}
int main(){
	int n,key,i=0;
	printf("Enter  number of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter key value");
		scanf("%d",&key);
	root = creation(root,key);
}
	xtraverse(root);
}