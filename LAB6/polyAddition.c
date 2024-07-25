#include<stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int expo;
    struct node* next;
}*start=NULL,*p,*temp,*start1=NULL,*start2=NULL,*start3,*p1,*p2,*n;
struct node* poly_creation(struct node* start);
void traverse(struct node* start );
struct node * poly_add(struct node*p1,struct node*p2);
void main(){
    int choice;
    do{  
        printf("1.creation of the polynomial\n2.poly_addition\n");
        printf("enter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            start=poly_creation(start);
            break;
            case 2:
            p1=poly_creation(start1);
            p2=poly_creation(start2);
            start3=poly_add(p1,p2);
            break;
            default:
            printf("invalid case.\n");

        }
    }while(choice!=0);
    
}
struct node* poly_creation(struct node* start){
    int terms;
    printf("enter the number terms:\n");
    scanf("%d",&terms);
for( int i=1;i<=terms;i++){
      int coeff,ex;
      printf("enter the coeff and expo respectively:\n");
      scanf("%d %d",&coeff,&ex);
      temp=(struct node*)malloc(sizeof(struct node));
      temp->coef=coeff;
      temp->expo=ex;
      temp->next=NULL;
            if(start==NULL)
                 start=temp;

            else if(start->next==NULL||ex>start->expo){
                         if(ex>start->expo)
                            {
                              temp->next=start;
                                start=temp;
                             }
                           else if(start->expo==ex){
                                start->coef+=coeff;
                            }
                            else
                            {
                                start->next=temp;
                            }
                                                }
else{    int flag;
         p=start;
         while(p!=NULL){
            if(p->expo==ex){
                p->coef=p->coef+coeff;
                free(temp);
                flag=1;
                break;
            }
        p=p->next;
         }
         if(flag!=1){
              p=start;
                 while(p->next!=NULL&& p->next->expo>ex){
                                   p=p->next;
                                            }
                temp->next=p->next;
                p->next=temp;

}
}
}
traverse(start);
return start;

}
void traverse(struct node* start){
    printf("\npolynomial terms :\n");
    if(start==NULL)
    printf("polynomial is empty\n");
    else
    {
        p=start;
        while(p!=NULL){
            printf("%dX^%d+",p->coef,p->expo);
            p=p->next;
        }
        printf("0");
        printf("\n");
    
    }
}
struct node* poly_add(struct node* p1,struct node*p2){
 
struct node *p3,*start3=NULL;
 if(p1==NULL&&p2==NULL)
{
    return start3;
} 
while(p1!=NULL && p2!=NULL){
     temp=(struct node*)malloc(sizeof(struct node));
     if(start3==NULL){
        start3=temp;
        p3=temp;
     }
     else{
        p3->next=temp;
        p3=temp;
     }
     if(p1->expo > p2->expo)
     {
        temp->coef=p1->coef;
        temp->expo=p1->expo;
        p1=p1->next;
     }
     else if(p2->expo > p1->expo){
        temp->coef=p2->coef;
        temp->expo=p2->expo;
        p2=p2->next;
     }
     else if(p1->expo==p2->expo){
        temp->coef=p1->coef+p2->coef;
        temp->expo=p1->expo;
        p1=p1->next;
        p2=p2->next;
     }
}
struct node *p;
if(p1!=NULL){
p=p1;
}
else
p=p2;
while(p!=NULL){
    temp=(struct node*)malloc(sizeof(struct node));
    if(start3==NULL){
        start3=temp;
        p3=temp;
    }
    else{
        p3->next=temp;
        p3=temp;
    }
    temp->coef=p->coef;
    temp->expo=p->expo;
    p=p->next;
}
printf("addition of two polynomials are :\n");
traverse(start3);
return start3;
}
