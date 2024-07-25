#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
    }*p,*start,*temp,*temp1,*temp2,*p1,*p2,*p3;

struct node* creation(void){
int i,n,x;
printf("enter the n value:\n");
scanf("%d",&n);

 for(i=1;i<=n;i++){
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter x value\n");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        p=temp;
    }

    else{
    p->next=temp;
    p=temp;
    }

 }
printf("single linked list is created.\n");
    return start;
}
void insertion_begin(void){
    //create a new node;
int x1;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the x1 value\n");
    scanf("%d",&x1);
    temp->data=x1;
    temp->next=NULL;
    if(start==NULL)
    { start=temp;
    }
    else
    {
        temp->next=start;
        start=temp;
    }


printf("%d is first entered element\n",start->data);


}

void traverse(void){

struct node  *start1=creation();
p=start1;
while(p!=NULL)
{
printf("%d\n",p->data);
p=p->next;
}
printf(" traversal is completed\n");



}
void insert_back(void){
int x;
struct node *st=creation();
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the x1 value\n");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    if(start==NULL)
    { start=temp;
    }
    else{
    p=st;
    while(p->next!=NULL){
    p=p->next;
    }
    p->next=temp;
    printf("last num is %d",p->next->data);
    }


}
void specified_pos(void){
    int x,pos=0,count=0,k;
struct node *st=creation();
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the x1 value\n");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    if(start==NULL)
    { start=temp;
    }
     else{
        p=st;
        while(p!=NULL)
    {
        count+=1;
        p=p->next;
    }
    printf("enter the position number\n");
    scanf("%d",&pos);
     if(pos>0 && pos<=count+1){
        if(pos==1){
            insertion_begin();
        }
        else if(pos==count+1){
            insert_back();
        }
        else
        { p=st;
            for(k=1;k<=pos-1;k++){
                p=p->next;
            }
             temp->next=p->next;
            p->next=temp;


        }

    }


     }
printf("%d is the  data at node;\n",p->next->data);

}
void deletion(struct node *st,int pos){
 int count=0,k;
//struct node *st=creation();
p=st;
while(p!=NULL){
count+=1;
p=p->next;
}
if(pos>0&& pos<=count){
if(pos==1){
temp=start;
start=start->next;
temp->next=NULL;
free(temp);
printf("%d is not data in temp.\n its a radom value\n",temp->data);
}
else if(pos==count)
{p=st;
while(p->next->next!=NULL){
      p=p->next;

}
temp=p->next;
p->next=NULL;
free(temp);

printf("%d is not value of temp",temp->data);
}
else {
    p=start;
for(k=1;k<=pos-1;k++){
      p=p->next;
}
temp=p->next;
temp->next=p->next;
temp->next=NULL;
free(temp);
printf("%d is at present pos",temp->data);
}

}

else
printf("entered invalid address.");

}
void search(void){
int flag=0,m;
struct node *st=creation();

printf("enter the input:\n");
scanf("%d",&m);
if(st==NULL)
printf("ll is empty");

else {
p=st;
while(p!=NULL){
if(p->data==m)
{
flag =1;
break;
}
else
p=p->next;

}
if(flag==1)
printf("element found.");
else
    printf("not found");

}

}
void  sorting(struct node *st){
//struct node *st=creation();
int x;
if(st==NULL){
    printf("ll is empty\n");

}
else if(st->next==NULL)
printf("only one node is there.\n so no need of sorting.");
else{
for(temp1=st;temp1!=NULL;temp1=temp1->next){
    for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next){
if(temp1->data >temp2->data){
    x=temp2->data;
    temp2->data=temp1->data;
    temp1->data=x;
}

    }
}
}
p=st;

while(p!=0)
{
printf("%d\n",p->data);
p=p->next;
}
printf(" traversal is completed");

}
void reversing(void){
creation();
printf("%d is the first element before resversing \n",start->data);
if(start==NULL){
    printf("LL is empty");
}
else if(start->next==NULL) {
    printf("only one node is there.");
}
else{
 p1=start;
 p2=p1->next;
 p3=p2->next;
 p2->next=p1;
 p1->next=NULL;
 while(p3!=NULL){
p1=p2;
p2=p3;
p3=p2->next;
p2->next=p1;
 }
 start=p2;
 printf("%d is first  element after revesing LL\n",start->data);
}
}
void delete_node_element(void){
creation();
    int element,c=0,pos=0;
printf("enter the element:\n");
scanf("%d",&element);
p=start;
while(p!=NULL){
    c+=1;
if(p->data==element){
    break;
}
else
p=p->next;
}
pos=c;
deletion(start,pos);
}
struct node*  concatenation(void){
struct node *st1=creation(),*st2=creation(),*ex;
ex=st1;
while(ex!=NULL){
ex=ex->next;
}
printf("elements after concatenation:\n");
ex=st2;
p=st1;
while(p!=NULL){
    printf("\n%d\n",p->data);
    p=p->next;
}

return st1;
}
void merging(void){
     struct node *n=concatenation();
     printf("elements after merging :\n");
     sorting(n);
}
void  delete_all_duplicate_elements(void){
struct node *st=creation();
int element,c=0,pos;
printf("enter the element:");
scanf("%d",&element);
p=st;
while(p!=NULL)
{  
    if(p->data==element)
    {
         c+=1;
    }
    else
    p=p->next;
}
printf("%d is count",c);
/*
while(flag==1){
while (p!=NULL)
{   
c+=1;
    if(p->data==element)
    {
        pos=c;
        deletion(start,pos);
        c=0;
    }
    else
    p=p->next;
}
*/

}

int main(){
    int ch,pos;
    printf("1.creation\n2.insertion\n3.traversal\n4.insert_end\n5.");
    printf("enter the case:\n");
    scanf("%d",&ch);
    switch(ch){
case 1:creation();
       break;
case 3:traverse();
break;
//case 2:insertion_begin();
  //     break;
case 2:creation();
insertion_begin();
break;
case 4:
insert_back();
break;
case 5:
specified_pos();
break;
case 6: 
printf("enter the position:");
 scanf("%d",&pos);
start=creation();
deletion(start,pos);
break;
case 7:
search();
break;
case 8:
start=creation();
sorting(start);
break;
case 9:
reversing();
break;
case 10:
concatenation();
break;
case 11:
merging();
break;
case 12:
delete_node_element();
break;
case 13:
delete_all_duplicate_elements();
break;
default :
printf("entered the invalid data.");
    }
}





