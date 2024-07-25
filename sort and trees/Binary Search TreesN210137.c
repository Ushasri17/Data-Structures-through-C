//Binary search tree:
#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node*left;
struct node *right;
}*temp,*p,*root=NULL;
struct node*insert_BST(struct node*root,int key);
struct node*newnode(int value);
void inorder(struct node*root);
void preorder(struct node*root);
void postorder(struct node*root);
struct node*min_value(struct node*root);
struct node*deletion_BST(struct node *root,int key);
void count_nodes();
void count_nodesi();
void count_nodese();
int height(struct node*root);
struct node* search(struct node*root,int k);


int main(){
int choice,ke,k,val,e,neww;
    printf("\n1.Insertion\n2.Deletion\n3.INorder Traversal\n4.PREorder Traversal\n5.POSTorder Traversal\n6.No.of nodes\n7.No.of Internal nodes\n8.No.of External nodes\n9.Height\n10.Searching\n");
do{
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1: neww=1;
           while(neww!=0){
           printf("Enter key value:");
           scanf("%d",&ke);
           root=insert_BST(root,ke);
           printf("Enter 1 to continue and 0 to exit:");
           scanf("%d",&neww);
            }
           inorder(root);
           break;
    case 2: neww=1;
            while(neww!=0){
             printf("Enter key value:");
             scanf("%d",&e);
             root=deletion_BST(root,e);
             printf("\nEnter 1 to continue and 0 to exit:");
             scanf("%d",&neww);
             }
             inorder(root);
             break;
    case 3:inorder(root);
           break;
    case 4:preorder(root);
           break;
    case 5:postorder(root);
           break;
    case 6:count_nodes();
           break;
    case 7:count_nodesi();
           break;
    case 8:count_nodese();
           break;
    case 9:printf("The height of tree is:%d\t",height(root));
           break;
    case 10:printf("\nEnter the element to find:");
            scanf("%d",&k);
            if(search(root,k)==NULL){
               printf("Search not found");
              }
            else{
                printf("Search found successfully");
            }
           break;
    }
}while(choice!=0);
}

struct node*newnode(int value){
temp=(struct node*)malloc(sizeof(struct node));
temp->data=value;
temp->left=NULL;
temp->right=NULL;
return temp;
}

struct node*insert_BST(struct node*root,int key){
if (root==NULL){
    return newnode(key);
}
else if(key<root->data){
    root->left=insert_BST(root->left,key);
}
else{
    root->right=insert_BST(root->right,key);
}
return root;
}

void inorder(struct node*root){
if (root==NULL){
    return ;
}
inorder(root->left);
printf("%d\t",root->data);
inorder(root->right);
}

void preorder(struct node* root){
if (root==NULL){
    return;
}
else{
printf("%d\t",root->data);
preorder(root->left);
preorder(root->right);
}
}

void postorder(struct node* root){
if (root==NULL){
    return;
}
else{
postorder(root->left);
postorder(root->right);
printf("%d\t",root->data);
}
}

struct node*min_value(struct node*root){
p=root;
while(p!=NULL && p->left!=NULL){
    p=p->left;
}
return p;
}

struct node*deletion_BST(struct node*root,int key){
if (root==NULL){
    printf("Element not found!!");
    return root;
}
else if(key<root->data){
    root->left=deletion_BST(root->left,key);
}
else if(key>root->data){
    root->right=deletion_BST(root->right,key);
}
else{
    if (root->left==NULL){
        temp=root->right;
        free(root);
        return temp;
    }
    else if(root->right==NULL){
        temp=root->left;
        free(root);
        return temp;
    }
    else{
        temp=min_value(root->right);
        root->data=temp->data;
        root->right=deletion_BST(root->right,temp->data);
    }
}
return root;
}
void count_nodes(){
int c=0;
c=num_nodes(root);
printf("No.of nodes is:%d\t",c);
}

int num_nodes(struct node *root){
if (root==NULL){
    return 0;
}
else{
    return num_nodes(root->left)+num_nodes(root->right)+1;
}
}

void count_nodesi(){
int c=0;
c=num_nodesi(root);
printf("No.of Internal nodes is:%d\t",c);
}

int num_nodesi(struct node*root){
if (root==NULL){
    return 0;
}
else if (root->left==NULL && root->right==NULL){
    return 0;
}
else{
    return num_nodesi(root->left)+num_nodesi(root->right)+1;
}
}

void count_nodese(){
int c=0;
c=num_nodese(root);
printf("No.of External nodes is:%d\t",c);
}

int num_nodese(struct node*root){
if (root==NULL){
    return 0;
}
else if(root->left==NULL && root->right==NULL){
    return 1;
}
else{
    return num_nodese(root->left)+num_nodese(root->right);
}
}

int height(struct node*root){
if (root==NULL){
    return 0;
}
else{
    int l=height(root->left);
    int r=height(root->right);
    if (l<r){
        return r+1;
    }
    else{
        return l+1;
    }
}
}

struct node* search(struct node *root,int k){
if(root==NULL || root->data==k){
    return root;
}
else{
    if (k<root->left){
       return search(root->left,k);
    }
return search(root->right,k);
}
}
