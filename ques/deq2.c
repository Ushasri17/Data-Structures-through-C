 #include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL,*p,*temp;
struct node *Enque_rear(int x)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    return front;
}
void Deque_front()
{
    if(front==NULL)
        printf("queue is empty\n");
    else
    {
        temp=front;
        printf("deleted element is %d\n",front->data);
        if(front==rear)
            front=rear=NULL;
        else
            front=front->next;
        free(temp);
    }
}
struct node* Enque_front(int x)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        temp->next=front;
        front=temp;
    }
    return front;
}
void Deque_rear()
{
    if(front==NULL)
        printf("queue is empty\n");
    else
    {
        temp=rear;
        printf("deleted element is %d\n",rear->data);
        if(front==rear)
            front=rear=NULL;
        else
        {
            p=front;
            while(p->next!=rear)
                p=p->next;
            rear=p;
            rear->next=NULL;
        }
        temp->next=NULL;
        free(temp);
    }
}
void traverse()
{
    if(front==NULL)
        printf("queue is empty\n");
    else
    {
        for(p=front;p!=NULL;p=p->next)
            printf("%d  ",p->data);
        printf("\n");
    }
}
void main()
{
    printf("enter no.of elements to be inserted at rear:");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter element:");
        scanf("%d",&x);
        front=Enque_rear(x);
    }
    printf("enter no.of elements to delete at front:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        Deque_front();
    }
    traverse();
    printf("enter no.of elements to be inserted at front:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter element:");
        scanf("%d",&x);
        front=Enque_front(x);
    }
    traverse();
    printf("enter no.of elements to delete at rear:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        Deque_rear();
    }
    traverse();
} 