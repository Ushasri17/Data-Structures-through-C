#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int cq[MAX],front=-1,rare=-1;
void enque(void);
void traversal(void);
void deque(void);
void main(){
    int choice;
    do{ printf("\n1.enque\n2.traversal\n3.deque\n");
        printf("enter the choice ");
        scanf("%d",&choice);
         

        switch(choice){
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
            printf("entered the wrong case:");
        }
        
    }while(choice!=0);
}
void enque(){
    int x;
printf("enter the data value:");
scanf("%d",&x);
if(front==((rare+1)%MAX)){
    printf("queue is full");
}
else
{ rare=(rare+1)%MAX;
 cq[rare]=x;
 if(front==-1)
    front=0;
}
}
void traversal(){
    int i;
    if(front==-1){
        printf("cq is empty\n");
    }
    else{
        i=front%MAX;
        do{
        printf("%d\n",cq[i]);
        i=(i+1)%MAX;
        }while(i!=((rare+1)%MAX));
    }
   // printf("traversal is completed");
}
void deque(){
    if(front==-1)
    printf("circular queue is empty");
    else{
        printf("%d is deleting element",cq[front]);
        if(rare==front)
        front=rare=-1;
        else
        front=(front+1)%MAX;
    }
}