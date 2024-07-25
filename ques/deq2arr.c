 #include<stdio.h>
#define max 10
int front=-1,rear=-1,deq[max];
void enqueue_rear(int x)
{
    if(rear>=max-1)
        printf("queue is overflow\n");
    else
    {
        deq[++rear]=x;
        if(front==-1)
            front=0;
    }
}
void dequeue_front()
{
    if(front==-1)
        printf("queue is empty\n");
    else
    {
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
            printf("deleted element is %d\n",deq[front++]);
    }
}
void traverse()
{
    int i;
    if(front==-1)
        printf("queue is empty\n");
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d   ",deq[i]);
        printf("\n");
    }
}
void enqueue_front(int x)
{
    if(front==0)
        printf("there is no space at front end\n");
    else
    {
        deq[--front]=x;
    }
}
void dequeue_rear()
{
    if(rear==-1)
        printf("queue is empty\n");
    else
    {
        printf("deleted element is %d\n",deq[rear]);
        if(front==rear)
            front=rear=-1;
        else
            rear=rear-1;
    }
}
void main()
{
    printf("enter no.of elements inserted at rear end:");
    int n,i,x,d;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter element:");
        scanf("%d",&x);
        enqueue_rear(x);
        if(rear>=max-1)
            break;
    }
    printf("enter no.of elemtes to be deleted at front end:");
    scanf("%d",&d);
    for(i=0;i<d;i++)
    {
        dequeue_front();
        if(front==-1)
            break;
    }
    traverse();
    printf("enter no.of elements inserted at front end:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter element:");
        scanf("%d",&x);
        enqueue_front(x);
        if(front==0)
            break;
    }
    printf("enter no.of elemtes to be deleted at rear end:");
    scanf("%d",&d);
    for(i=0;i<d;i++)
    {
        dequeue_rear();
        if(rear==-1)
            break;
    }
    traverse();

}