// Double ended queue
#include <stdio.h>
#define MAX 10
int CQ[MAX] = {0}, front = -1, rear = -1;
void enqueue()
{
  int x;
  if (front == (rear + 1) % MAX)
  {
    printf("Double ended Queue is full!\n");
  }
  else
  {
    printf("Enter the data :");
    scanf("%d", &x);
    rear = (rear + 1) % MAX;
    CQ[rear] = x;
    if (front == -1)
    {
      front = 0;
    }
  }
}
void dequeue()
{
  if (front == -1)
  {
    printf("Double Ended Queue is empty!\n");
  }
  else if (front == rear)
  {
    printf("The deleting element is %d\n", CQ[front]);
    front = rear = -1;
  }
  else
  {
    front = (front + 1) % MAX;
  }
  printf("\n");
}
void traversal()
{
  int i;
  if (front == -1)
  {
    printf("Double Queue is empty!\n");
  }
  else
  {
    printf("The elements are :");
    i = front%MAX;
    do
    {
      printf("%d ", CQ[i]);
      i = (i + 1) % MAX;

    } while (i != (rear + 1) % MAX);
  }
  printf("\n");
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
    printf("(1)-to enqueue\n(2)-to dequeue\n(3)-to traversal\n(4)-enqueue at front\n(5)-dequeue at rear\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
    {
      enqueue();
      break;
    }
    case 2:
    {
      dequeue();
      break;
    }
    case 3:
    {
      traversal();
      break;
    }
    case 4:
    {
      enqueue_at_front();
      break;
    }
    case 5:
    {
      dequeue_at_rear();
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