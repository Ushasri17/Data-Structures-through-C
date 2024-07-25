#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node *next;
}*start,*end,*p,*temp;
struct node* creation(struct node* start);
void traverse(struct node *start);
void insertion_at_begin(void);
void insertion_at_end(void);
void insertion_at_spec(void);
void deletion_at_begin(void);
void deletion_at_end(void);
void deletion_at_spec(void);
int main(){
    int choice;
            //printf("\n1.creation\n2.travese\n3.insertion_at_begin\n4.insertion_at_end\n5.insertion_at_spec\n6.deletion_begin\n7.deletion_end\n8.deletion_at_spec\n\n");
    do{
       printf("\n1.creation\n2.travese\n3.insertion_at_begin\n4.insertion_at_end\n5.insertion_at_spec\n6.deletion_begin\n7.deletion_end\n8.deletion_at_spec\n\n");
        printf("enter the choice:");
        scanf("%d",&choice);
switch(choice){
case 1:
start=creation(start);
break;
case 2:
traverse(start);
break;
case 3:
insertion_at_begin();
break;
case 4:
insertion_at_end();
break;
case 5:
insertion_at_spec();
break;
case 6:
deletion_at_begin();
break;
case 7:
deletion_at_end();
break;
case 8:
deletion_at_spec();
break;
default:
printf("entered the wrong case.");
    }
}while(choice!=0);
}
struct node* creation(struct node* start){
    int node,x,i;
    printf("enter the number of nodes to be created:");
    scanf("%d",&node);
    for(i=0;i<node;i++){
//create a temp node
temp=(struct node*)malloc(sizeof(struct node*));
printf("enter the data:");
scanf("%d",&x);
temp->data=x;
temp->next=NULL;
if(start==NULL){
start=temp;
end=temp;
temp->next=start;

}
else{
end->next=temp;
temp->next=start;
end=temp;
}
    }
    printf("SCL is completed.\n");
    return start;
}
void traverse(struct node *start){
    if(start==NULL)
    printf("SCL is empty.");
    else
    { p=start;
    while(p->next!=start){

        printf("%d\n",p->data);
         p=p->next;
    }
    printf("%d\n",p->data);
printf("traversal is completed.\n");
    }
}
void insertion_at_begin(){
    //create new node temp;
    int x1;
    printf("create a new node temp.");
    temp=(struct node*)malloc(sizeof(struct node*));
    printf("\nenter the x1 value:");
    scanf("%d",&x1);
    temp->data=x1;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
        start->next=start;
        end=start;
    }
    else{
        temp->next=start;
        start=temp;
        end->next=start;
    }
}
void insertion_at_end(void){
    int x1;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the x1:");
    scanf("%d",&x1);
    temp->data=x1;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
        start->next=temp;
        end=start;
    }
    else{
 end->next=temp;
 end=temp;
 temp->next=start;
    }

}
void insertion_at_spec(void){
    int x1,c=0,pos,k;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the element to be inserted");
scanf("%d",&x1);
printf("enter the pos:");
scanf("%d",&pos);
temp->data=x1;
temp->next=NULL;
if(start==NULL){
    start=temp;
    end=temp;
    start->next=temp;
}
else{
p=start;
while(p->next!=start){
    c+=1;
    p=p->next;
}
c=c+1;
if(pos>0&&pos<=c+1){
if(pos==1)
insertion_at_begin();
else if(pos==c+1)
insertion_at_end();
else {
p=start;
 for(k=1;k<pos-1;k++){
p=p->next;
 }
 temp->next=p->next;
 p->next=temp;
}
}
}
}
void deletion_at_begin(){
if(start==NULL){
    printf("SCL is empty.\n");
}
else if(start->next==start){
    temp=start;
    start=end=temp->next=NULL;
 free(temp);
}
else {
temp=start;
start=start->next;
end->next=start;
temp->next=NULL;
free(temp);
}
 
}
void deletion_at_end(){
    if(start==NULL){
        printf("single circular list is empty.");
    }
    else{
        p=start;
        while(p->next->next!=start){
            p=p->next;
        }
         temp=end;
         end=p;
         end->next=start;
         temp->next=NULL;
         free(temp);
    }
}
void deletion_at_spec(void){
    int pos;
    printf("enter the pos:");
    scanf("%d",&pos);
if(start==NULL){
printf("SCL is empty.");
}
else if(start->next==NULL){

    temp=start;
    start=end=temp->next=NULL;
    free(temp);
}
else{
    int c=0,k;
    p=start;
    while(p->next!=start){
        c+=1;
        p=p->next;

    }
    c=c+1;
    if(pos>0&&pos<c){
     if(pos==1)
     deletion_at_begin();
     else if(pos==c)
     deletion_at_end();
     else{
p=start;
for(k=1;k<pos-1;k++){
    p=p->next;
}
temp=p->next;
p->next=temp->next;
temp->next=NULL;
free(temp);
}
}
}
}
