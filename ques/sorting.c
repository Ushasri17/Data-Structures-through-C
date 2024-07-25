#include<stdlib.h>
#include<stdio.h> 
void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void  insertion_sort(int a[],int n){
    int i,j=0,key;
    for( i=0;i<n;i++){
    key=a[i];
    j=i-1;
    while(j>=0&&a[j]>key){
        a[j+1]=a[j];
        j=j-1;
    }
    a[j+1]=key;
    }
    display(a,n);
}
void swap(int *p,int*q){
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
void  selection_sort(int a[],int n ){
    int i,j,min_index;
    for(i=0;i<n;i++){
        min_index=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
        }
        swap(&a[i],&a[min_index]);
    }
    
display(a,n);
}

 void main(){
    
    int choice;
    do{
        int a[50],n;
        printf("enter the size of the array:");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
        printf("element-[%d]:",i+1);
        scanf("%d",&a[i]);
        }
        printf("\n(1).insertion-sort\n(2).selection\n");
        printf("enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:insertion_sort(a,n);
                    break;
            case 2:selection_sort(a,n);
                    break;
            default:
            printf("entered the invalid case......\n");
            break;
        }
    }while(choice!=0);

    

     
    
}