// Double ended queue
#include <stdio.h>
#define MAX 10
int CQ[MAX] = {0}, front = -1, rear = -1;
  void traversal(){
    if(front==-1)
    printf("queue is empty");
    else{ 
        for( int i=front;i<=rear;i++){
            printf("%d\n",CQ[i]);
        }
    }
}

void enqueue_at_front()
{
  int x;
  if (front == 0)
  {
    printf("Double ended queue is full in front\n");
  }

  else
  {
    printf("Enter data:");
    scanf("%d", &x);
    if (front == -1)
    {
      front = front + 1;
      CQ[front] = x;
      if (rear == -1)
      {
        rear = 0;
      }
    }
    else
    {
      front = front - 1;
      CQ[front] = x;
    }
  }
}
void dequeue_at_rear()
{
  if (front == -1)
  {
    printf("Double Queue is empty!\n");
  }
  else if (front == rear)
  {
    printf("Deleting element is %d\n", CQ[front]);
    front = rear = -1;
  }
  else
  {
    printf("Deleting element is %d\n", CQ[rear]);
    rear = rear - 1;
  }
}

void main()
{
  int choice = 1, c, i;
  while (choice)
  {
    printf("Enter value of required operation:\n");
    printf(" \n(1)-enqueue at front\n(2)-dequeue at rear\n(3)-to traversal\n");
    scanf("%d", &c);
    switch (c)
    {
        case 1:
    {
      enqueue_at_front();
      break;
    }
    case 2:
    {
      dequeue_at_rear();
      break;
    }
    
    case 3:
    {
       traversal();
      break;
    }
     
    default:
    {
      c = 0;
      break;
    }
    }
  }
}
















































































/*#include<stdio.h>
#define MAX 8
int q[MAX],front=-1,rare=-1;
void enque_at_begin(void);
void deque_at_end(void);
void priority_queue(void);
void traversal();
    
void main(){
    //double ended que
    int choice;
    printf("\n1.enque_at_begin\n2.deque_at_end.\n3.traversal.\n");
    do{
printf("enter  the choice:");
scanf("%d",&choice);
switch (choice)
{
case 1:
    enque_at_begin();
    break;
case 2:
    deque_at_end();
    break;
case 3:
       traversal();
       break;
     
default:
    break;
}
    }while(choice!=0);

}
void enque_at_begin(){
    int x;
    printf("enter the x value:");
    scanf("%d",&x);
    if(front==0)
    printf("space is not available at front end");
    else if(front==-1)
    {
        q[++front]=x;
        if(rare==-1)
        rare=0;
    }
    else{
        front=front-1;
        q[front]=x;
    }
}
void deque_at_end(){
    printf("deleting element is %d",q[rare]);
    if(front==-1)
    printf("queu is empty");
    else
    {
        if(front==rare)
         front=rare=-1;
         else{
            rare=rare-1;
         }
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
}*/