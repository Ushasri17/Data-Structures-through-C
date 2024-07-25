#include<stdio.h>
#include<stdlib.h>
struct node{
     struct node* prev;
     int data;
     struct node *next;
 }*start,*p,*temp,*end;
struct node* creation(struct node* start);
void traversal(struct node*);
void new_node(void);
void insertion_at_begin(void);
void insertion_at_end(void);
void insertion_at_spec(void);
void deletion_at_begin(void);
void deletion_at_end(void);
void deletion_at_spec(void);
void main(){
int choice;
        printf("\nenter the following cases for DLL operations:");
      //  printf("\n\n1.creation\n2.traversal\n3.insertion_at_begin\n4.insertion_at_end\n5.insertion_at_spec\n6.deletion_at_begin\n7.deletion_at_end\n8.deletion_at_spec\n\n");    
do{            
        printf("\n\n1.creation\n2.traversal\n3.insertion_at_begin\n4.insertion_at_end\n5.insertion_at_spec\n6.deletion_at_begin\n7.deletion_at_end\n8.deletion_at_spec\n\n");
        printf("\nenter the choice :");
        scanf("%d",&choice);
switch (choice)
{
        case 1:start= creation(start);
        break;
        case 2:traversal(start);
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
        printf("exit :)");
        break;
}
}while(choice!=0);

}
struct node* creation(struct node* start){
int n,x,i;
printf("enter the number of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the data value:");
        scanf("%d",&x);
        temp->data=x;
        temp->prev=temp->next=NULL;
        if(start==NULL){
        start=temp;
        end=temp;
}
else{
        end->next=temp;
        temp->prev=end;
        end=temp;
}
}
return start;
}
void  traversal(struct node *start){
if(start==NULL){
        printf("DLL is empty.");
}
else{
     
    p=start;
    while(p!=NULL){
        printf("\n%d",p->data);
        p=p->next;
    }
    printf("\ntraversal from forward completed.");
    p=end;
    while(p!=NULL){
        printf("\n%d",p->data);
        p=p->prev;
    }
    printf("\ntraversal from backside completed.");
}


}
void new_node(){
        //create a new node;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the new data:");
        int x1;
        scanf("%d",&x1);
        temp->data=x1;
        temp->next=temp->prev=NULL;

}
void insertion_at_begin(){
         new_node();
        if(start==NULL){
                start=end=temp;
        }

        else{
                temp->next=start;
                start->prev=temp;
                start=temp;
        }



}
void insertion_at_end(){
         new_node();
         if(start==NULL){
                start=end=temp;
         }
         else{
                end->next=temp;
                temp->prev=end;
                end=temp;
         }

}
void insertion_at_spec(){
        new_node();
        if(start==NULL){
                start=end=temp;
        }
        int c=0,k,pos;
        printf("enter the pos:");
        scanf("%d",&pos);
        p=start;
        while(p!=NULL){
                c+=1;
                p=p->next;
        }
        if(pos>0&&pos<=c+1){
                if(pos==1){
                        insertion_at_begin();
                }
                else if(pos==c+1)
                insertion_at_end();
                else{
                p=start;
                 for(k=1;k<pos-1;k++){
                        p=p->next;
                 }
                 p->next->prev=temp;
                 temp->next=p->next;
                 p->next=temp;
                 temp->prev=p;
                }

        }
}
void deletion_at_begin(){
        if(start==NULL){
                printf("DLL is empty");
        }
        else if(start->next==NULL){
                
                temp=start;
                end=temp;
                start=end=NULL;
               // temp->next=temp->prev=NULL;
                free(temp);
        }
        else{
                temp=start;
                start=start->next;
                start->prev=NULL;
                temp->next=temp->prev=NULL;
                free(temp);

        }

}
void deletion_at_end(){
          if(start==NULL){
                printf("DLL is empty");
        }
        else if(start->next==NULL){
                
                temp=start;
                end=temp;
                start=end=NULL;
                temp->next=temp->prev=NULL;
                free(temp);
        }
        else{
                p=start;
                while(p->next->next!=NULL){
                        p=p->next;
                }
                temp=end;
                end=p;
                p->next=NULL;
                temp->next=temp->prev=NULL;
                free(temp);
        }
}
void deletion_at_spec(){
        if(start==NULL){
                 printf("DLL is empty");
        }
        int c=0,k,pos;
        printf("enter the pos:");
        scanf("%d",&pos);
        p=start;
        while(p!=NULL){
                c+=1;
                p=p->next;
        }
        if(pos>0&&pos<=c){
                if(pos==1){
                         deletion_at_begin();
                }
                else if(pos==c)
                 deletion_at_end();
                else{
                p=start;
                 for(k=1;k<pos-1;k++){
                        p=p->next;
                 }
                  temp=p->next;
                  p->next=temp->next;
                  temp->next->prev=p;
                  temp->next=temp->prev=NULL;
                  free(temp);
                }
        
        }
        }