#include<stdio.h>
#define MAX 5
int q[MAX],front=-1,rare=-1;
void enque(int x); 
void deque(void);
void traversal(void);
void main(){ 
    int choice;
    printf("\n1.enque\n2.deque\n3.traversal\n");
    do{  
        printf("enter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:int x;
            printf("enter the x value:");
            scanf("%d",&x);
            enque(x);
            break;
            case 2:
            deque();
            break;
            case 3:
            traversal();
            break;
            default:
            printf("entered the wrong details");
        }
    }while(choice!=0);
}
void enque(int x){
   if(rare>=MAX-1)
    printf("Queue is full\n");
else
{
    q[++rare]=x;
     if(front==-1)
     front=0;
} 
}
void deque(void){
    if(front==-1)
    printf("its empty");
    else if(rare==front)
    rare=front=-1;
    else{
        printf("deleting element-%d",q[front]);
        front=front+1;
    } 
}
void traversal(){
    if(front==-1)
    printf("queue is empty");
    else{ 
        for( int i=front;i<=rare;i++){
            printf("%d\n",q[i]);
        }
    }
}
