#include <stdio.h>
#include <stdlib.h>
struct node* creating(struct node *st);
void traversing();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void search();
void reverse();
void sorting();
void concatenate();
struct node{
int data;
struct node *next;
}*start,*temp,*p,*p1,*p2,*p3,*temp1,*temp2,*start1=NULL,*start2=NULL;
void main(){
	printf("1.Creating\n2.Traversing\n3.Insertion at beginning\n4.Insertion at ending\n5.Insertion at specified position\n6.Deletion at beginning");
	printf("\n7.Deletion at ending\n8.Deletion at specified position\n9.Searching\n10.Reversing\n11.Sorting\n12.Concatenation\n");
int choice;
    do{
//    printf("1.Creating\n2.Traversing\n3.Insertion at beginning\n4.Insertion at ending\n5.Insertion at specified position\n6.Deletion at beginning");
//	printf("\n7.Deletion at ending\n8.Deletion at specified position\n9.Searching\n10.Reversing\n11.Sorting\n12.Concatenation\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1: start=creating(start);
            break;
    case 2:traversing(start);
            break;
    case 3:insert_beg();
           break;
    case 4:insert_end();
           break;
    case 5:insert_pos();
            break;
    case 6:delete_beg();
           break;
    case 7:delete_end();
           break;
    case 8:delete_pos();
           break;
    case 9:search();
           break;
    case 10:reverse();
            break;
    case 11:sorting();
            break;
    case 12:concatenate();
             break;
    }
}while(choice!=0);
}

struct node* creating(struct node* start)
{
int n=1;
while(n!=0){
   temp=(struct node*)malloc(sizeof(struct node));
   printf("Enter the data:");
   scanf("%d",&temp->data);
   temp->next=NULL;
   if (start==NULL){
       start=p=temp;
     }
   else{
      p->next=temp;
      p=temp;
    }
   printf("Do you want to enter one more node (0 or 1):");
   scanf("%d",&n);
}
return start;
}

void traversing(struct node* start){
if (start==NULL){
    printf("Linked list is empty\n");
}
else{
    p=start;
    while(p!=0){
      //  printf("%d\n",p->data);
      printf("%d\t",p->data);
        p=p->next;
    }
}
}
void insert_beg(){
   int new=1;
while(new!=0){
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter data to the new node at the beginning:");
scanf("%d",&temp->data);
if (start==0){
    start=p=temp;
}
else{
    temp->next=start;
    start=temp;
}
printf("Enter 1 to insert another new node at beginning:");
scanf("%d",&new);
}
printf("After inserting at begin:\n");
traversing(start);
}

void insert_end(){
int hnew=1;
while(hnew!=0){
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter data to the new node at the ending:");
scanf("%d",&temp->data);
if (start==0){
    start=p=temp;
}
else{
    p=start;
    while(p->next!=NULL){
        p=p->next;
    }
p->next=temp;
}
printf("Do you want to insert another node at the end:(0 or 1)");
scanf("%d",&hnew);
}
printf("After inserting at end:\n");
traversing(start);
}
void insert_pos(){
int hnew=1,count=0,pos,k;
while(hnew!=0){
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter data to the new node at that position:");
scanf("%d",&temp->data);
if (start==0){
    start=p=temp;
    }
else{
p=start;
while(p!=0){
count+=1;
p=p->next;
    }
printf("Enter a position to insert a new node:");
scanf("%d",&pos);
if (pos==0){
    insert_beg();
}
else if (pos==count+1){
    insert_end();
}
else if (pos>0 && pos<=count+1){
p=start;
for (k=1;k<pos-1;k++){
    p=p->next;
    }
temp->next=p->next;
p->next=temp;
        }
else{
printf("Invalid position\n");
        }
    }
printf("Do you want to insert another node (0 or 1):");
scanf("%d",&hnew);
}
printf("After inserting at position:\n");
traversing(start);
}

void delete_beg(){
if (start==0){
    printf("Linked list is empty");
}
else if (start->next==0){
        temp=start;
        start=0;
        free(temp);
    }
else{
        temp=start;
        start=start->next;
        temp->next=0;
        free(temp);
    }
printf("After deleting at begin:\n");
traversing(start);
}

void delete_end(){
if (start==0){
        printf("Linked list is empty");
    }
else if (start->next==0){
       temp=start;
       start=0;
       free(temp);
    }
else{
       p=start;
       while(p->next->next!=0){
             p=p->next;
    }
       temp=p->next;
       p->next=0;
       free(temp);
    }
printf("After deleting at end:\n");
traversing(start);
}

void delete_pos(){
int pos,k,count=0;
printf("Enter the position to delete:");
scanf("%d",&pos);
if (start==0){
    printf("Linked list is empty\n");
}
else{
    p=start;
    while(p!=0){
        count+=1;
        p=p->next;
    }
    if (pos==1){
        delete_beg();
    }
    else if (pos==count+1){
        delete_end();
    }
    else{
        p=start;
        for (k=1;k<pos-1;k++){
            p=p->next;
        }
        temp=p->next;
        p->next=temp->next;
        temp->next=0;
        free(temp);
    }
}
printf("After deleting at position:\n");
traversing(start);
}

void search(){
int x,flag=0,pos=1,m;
printf("Enter a value for x:");
scanf("%d",&x);
p=start;
while(p!=0){
    pos+=1;
    if (p->data==x){
        flag=1;
        break;
    }
    else{
        p=p->next;
    }
}
if (flag==1){
    printf("Element found at:%d\n",pos-1);
}
else{
    printf("Element is not found\n");
}
}

void reverse(){
if (start==0){
    printf("Linked list is empty");
}
else if(start->next==0){
    printf("Linked list consists of only one node");
}
else{
    p1=start;
    p2=p1->next;
    p3=p2->next;
    p2->next=p1;
    p1->next=0;
    while(p3!=0){
        p1=p2;
        p2=p3;
        p3=p2->next;
        p2->next=p1;
    }
start=p2;
}
printf("After reverisng:\n");
traversing(start);
}
void sorting(){
int x;
if (start==0){
    printf("Linked list is empty");
}
else if(start->next==0){
    printf("Linked list consists of only one node");
}
else{
    for(temp1=start;temp1!=0;temp1=temp1->next){
        for (temp2=temp1->next;temp2!=0;temp2=temp2->next){
            if (temp1->data>temp2->data){
                x=temp1->data;
                temp1->data=temp2->data;
                temp2->data=x;
            }
        }
    }
}
printf("After sorting:\n");
traversing(start);
}

void concatenate(){
start1=creating(start1);
traversing(start1);
start2=creating(start2);
traversing(start2);
p=start1;
while(p->next!=0){
    p=p->next;
}
p->next=start2;
start=start1;
printf("After concatenation of two linked lists:\n");
p=start;
while(p!=NULL){
    printf("%d\n",p->data);
    p=p->next;
}
}



