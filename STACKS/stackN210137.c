#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int s[MAX],x,top=-1,n;
int  push(int );
void traversal(void);
int pop(void); 
void peak(void);
void main(){
            int choice;
             printf("\n1.push\n2.pop\n3.traverse\n4.peak\n");
     int n,x=0;
do{     printf("\nenter the choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1:{
               printf("Enter no of elements needed:");
               scanf("%d",&n);
               push(n);
               break;
              }
        case 2:  x=pop();
               printf("%d is poped.",x);
               break;
        case 3:traversal();
               break;
        case 4:peak();
               break;
        default:
                printf("entered wrong case.\nEXIT :)\n");

        }

}while(choice!=0);
}
int  push(int n){
    if(top==MAX-1 || n==0){
        if(top==MAX-1)
        printf("stack is full");
        else
        printf("inserted ur elements");
        return 0;
    }
    else{
    int x;
    printf("enter data :");
    scanf("%d",&x);
    s[++top]=x;
   push(n-1);
   return 0;
   }
}
void traversal(){
    if(top==-1)
    printf("Stack is empty.");
    else{ 
        int i;
        for(i=top;i>=0;i--){
            printf("%d\n",s[i]);
        }
    }
}
int  pop(){
    if(top==-1)
    printf("stack is empty.");
    else{
        return s[top--];
    }
}
void peak(){
    if(top==-1)
    printf("stack is empty");
    else{
        printf("%d is peak value in Stack",s[top]);
    }

}
