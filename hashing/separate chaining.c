//Hashing
#include<stdio.h>
#include<stdlib.h>
#define size 5
struct node{
	int data;
	struct node*next;
}*temp,*p,*a[size];

void main(){
	int choice;
	do{
		printf("\n1.Insertion\n2.Deletion\n3.Searching\n");
		printf("Enter your choice:-");
		scanf("%d",&choice);
		switch(choice){
			case 1:insertion();
			break;
			case 2:deletion();
			break;
			case 3:search();
			break;
		}
	}while(choice!=0);
}

void insertion(){
	int new=1,value,hkey;
	while(new!=0){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:-");
		scanf("%d",&value);
		temp->data=value;
		temp->next=NULL;
		hkey=value%size;
		if(a[hkey]==NULL){
		   a[hkey]=temp;
		}
		else{
			p=a[hkey];
			while(p->next!=NULL){
				p=p->next;
			}
			p->next=temp;
		}
		printf("Enter 1 or 0:-");
		scanf("%d",&new);
	}
	traverse();
}
void deletion(){
	int hkey,value;
	printf("Enter value you want to delete:-");
	scanf("%d",&value);
	hkey=value%size;
	if(a[hkey]==NULL){
		printf("Chain is empty");
	}
	else{
		p=a[hkey];
		if(p->data==value){
			temp=p;
			a[hkey]=p->next;
			temp->next=NULL;
			free(temp);
	   }
	   else{
	   	while(p->next!=NULL){
	   		if(p->next->data==value){
	   			temp=p->next;
	   			p->next=temp->next;
	   			temp->next=NULL;
			   }
		   }
	   }
	}
	traverse();
}
void traverse(){
	int i;
	printf("New chain:-");
	for(i=0;i<size;i++){
		if(a[i]!=NULL){
			printf("%d\t",a[i]->data);
			printf("~~~\t");
		} 
	}
}

void search(){
	int value,pos,flag=1,i,hkey;
	printf("Enter value to search:-");
	scanf("%d",&value);
	hkey=value%size;
	for(i=0;i<size;i++){
		if(a[hkey]->data==value){
		//	pos=i;
			flag=0;
			break;
		}
		else{
			flag=1;
		}
	}
	if(flag==0){
		printf("Search found at %d",hkey);
	}
	else{
		printf("Search not found");
	}
}















