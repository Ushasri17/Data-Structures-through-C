#include<stdio.h>
#include<stdlib.h>
#define M 10
struct node{
    int data;
    struct node*next;
}*top=NULL,*p,*temp;
struct node* push(int x);
void traverse(struct node*top);
void pop(void);
void peak(void);
void main(){
    int choice;
    printf("enter the following cases:");
    
    do{
         printf("\n1.push\n2.traverse\n3.pop\n4.peak\n");
        printf("\nenter the choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:int x;
                   printf("enter the x value:");
                   scanf("%d",&x);
                   top=push(x);
                   break;
            case 2:
                  traverse(top);
                  break;
            case 3:
                  pop();
                  break;
            case 4:
                  peak();
                  break;
                  
            default:
            printf("enetered invalid case:");
        } 
    
    }while(choice!=0);
}
struct node* push(int x)
{    
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(top==NULL)
    top=temp;
    else{
    temp->next=top;
    top=temp;
    }
    return top;
    
}
void traverse(struct node *top){
    p=top;
    if(top==NULL)
    printf("stack is empty.");
    while(p!=NULL){
        printf("%d \n",p->data);
        p=p->next;
    }

}
void pop(){
    if(top==NULL)
    printf("stack is empty");
    else
    {
        temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
    }
    
}
void peak(){
    if(top==NULL)
    printf("stack is empty");
    else
    {
        printf("%d is peak value",top->data);
    }
}