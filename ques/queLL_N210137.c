#include<stdio.h>
#include<stdlib.h>
struct  node
{
    /* data */
    int data;
    struct node* next;
}*temp,*p,*start=NULL,*front=NULL,*rare=NULL;
void enque(void);
void traversal(void);
void deque(void);
void main(){
    int choice;printf("\n1.enque\n2.traversal.\n3.deque\n");
     do{ 
     printf("enter the choice:");
     scanf("%d",&choice);
    switch ( choice)
    {
    case 1:
          enque();
          break;
    case 2:
          traversal();
          break;
    case 3:
          deque();
          break;
    default:
    printf("Entered the wrong value");
    }

    }while(choice!=0);
}
void enque(){
    int data;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    if(front==NULL)
    {
        front=temp;
        rare=temp;
    }
     
    else
    {
         rare->next=temp;
         rare=temp;
    }

}
void traversal(){
if(front==NULL){
    printf("queue is empty");
}
else{
    p=front;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

}
void deque(){
    if(front==NULL){
        printf("it is empty list");
    }
    else if(front==rare){
        temp=front;
        front=rare=NULL;
        temp->next=NULL;
        free(temp);
    }
    else{
       temp=front;
        front=front->next;
        temp->next=NULL;
        free(temp);
    }
}