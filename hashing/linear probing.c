#include<stdio.h>
#include<stdlib.h>
#define size 5
int a[size],value;
void initial();
void main(){
	int choice;
	do{
		printf("\n1.Insertion\n2.Delete\n3.Searching\n");
		printf("Enter your choice:-");
		scanf("%d",&choice);
		switch(choice){
			case 1:insert();
			break;
			case 2:deletion();
			break;
			case 3:search();
			break;
		}
	}while(choice!=0);
}
void initial(int a[]){
	int i;
	for(i=0;i<size;i++){
		a[i]=-1;		}
}
void insert(){
	initial(a);
	int i,value,hkey,new=1;
	while(new!=0){
		printf("Enter value:-");
		scanf("%d",&value);
		hkey=value%size;
		for(i=0;i<size;i++){
			if(a[(hkey+i)%size]==-1){
				a[(hkey+i)%size]=value;
				break;
			}
			if(i==size){
				printf("Space is not available in hash table");	}
		}
		printf("Enter 1 or 0:-");
		scanf("%d",&new);	}
		traverse();		
}
void traverse(){
	int i;
	for(i=0;i<size;i++){
		if(a[i]!=-1)		printf("%d\t",a[i]);
		else	printf("~~~\t");
	}
}
void deletion(){
	int i,hkey,value,new=1;
	while(new!=0){
		printf("Enter value to delete:-");
		scanf("%d",&value);
		hkey=value%size;
		for(i=0;i<size;i++){
			if(a[(hkey+i)%size]==value){
				a[(hkey+i)%size]=-1;
				break;
			}
			if(i==size)
				printf("Not Found");
		}
		printf("Enter 1 or 0:-");
		scanf("%d",&new);
	}	traverse(a);
}
void search(){
	int i,hkey,val,pos,flag=0;
	printf("Enter value to search:-");
	scanf("%d",&val);
	hkey=value%size;
	for(i=0;i<size;i++){
		if(a[(hkey+i)%size]==val){
			pos=i;
			flag=1;
			break;		}
		else
		flag=0;		}
	if(flag==1)				printf("Search found at %d",pos);
	else					printf("Search not found ");
}






















