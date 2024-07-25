
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int arr[MAX];
int itemcount = 0;
void insert()
{
  int d, i;
  printf("Enter data:");
  scanf("%d", &d);
  if (itemcount == MAX - 1)
  {
    printf("Priority Queue is full!");
  }
  else if (itemcount == 0)
  {
    arr[itemcount] = d;
    itemcount++;
  }
  else
  {
    for (i = itemcount - 1; i >= 0; i--)
    {
      if (d > arr[i])
      {
        arr[i + 1] = arr[i];
      }
      else
      {
        break;
      }
    }
    arr[i + 1] = d;
    itemcount++;
  }
}
void delete()
{
  if (itemcount == 0)
  {
    printf("Priority Queue is empty!");
  }
  else
  {
    printf("The deleting element is %d", arr[itemcount - 1]);
    itemcount--;
  }
}
void display()
{
  int i;
  for (i = itemcount - 1; i >= 0; i--)
  {
    printf("%d  ", arr[i]);
  }
}
void main()
{
  int choice = 1, c;
  while (choice)
  {
    printf("ENTER THE FOLLWING CHOICE:\n(1)-insert\n(2)-delete\n(3)-display\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
    {
      insert();
      break;
    }
    case 2:
    {
      delete ();
      break;
    }
    case 3:
    {
      display();
      break;
    }
    default:
    {
      choice = 0;
      printf("entered invalid case....");
      break;
    }
    }
  }
}
























































/*
#include<stdio.h>
#include<stdlib.h>
int pq[100],itemcount=0,MAX;
void traversal(int pq[]){
    for(int k=itemcount-1;k>=0;k--){
        printf("%d ",pq[k]);
    }
printf("\n");
}
void insert_prior_queue( ){
    int data;
    printf("enter the max length of the array:");
    scanf("%d",&MAX);
    for(int i=0;i<MAX;i++){
    printf("enter the data:");
    scanf("%d",&data);
    if(itemcount==MAX )
    printf("queue is full.");
    else if( itemcount==0){
    pq[itemcount]=data;
    itemcount++;
    }
    else {
        int j;
        for( j=itemcount-1;j>=0;j--){
            if(data>pq[j]){
                pq[j+1]=pq[j];
            }
            else
            {
                break;
            }
        }
        pq[j+1]=data;
        itemcount++;
    }
    }
    traversal(pq);
} 

void main(){
    int choice;
    do{  printf("enter your choice:");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert_prior_queue( );
            break;
        
        default:
             printf("entered the invalid case.");
        }
    }while(choice==0);
    
    
}

 */