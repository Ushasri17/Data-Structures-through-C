//Quadratic probing
#include<stdio.h>
#include<stdlib.h>
#define size 5
int a[5];

int main(){
	int choice;
	do{
		printf("\n1.Insert\n2.Delete\n3.Searching\n");
		printf("Enter your choice:-");
		scanf("%d",&choice);
		switch(choice){
			case 1:inser();
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
    	a[i]=-1;
	}	
}

int inser(){
	initial(a);
	int i,value,hkey;
	int n=1;
	while(n!=0){
		printf("Enter value:-");
		scanf("%d",&value);
		hkey=value%size;
		for(i=0;i<size;i++){
			if(a[(hkey+i*i)%size]==-1){
				a[(hkey+i*i)%size]=value;
				break;
			}
			if(i==size){
				printf("Space is not available in hash table");
			}
		}
		printf("Enter 1 or 0:-");
		scanf("%d",&n);	
	}
	traverse(a);
}

int traverse(){
	int i;
	for(i=0;i<size;i++){
		if(a[i]!=-1){
			printf("%d\t",a[i]);
		}
		else{
			printf("~~~\t");
		}
	}
}

int deletion(){
	int value,hkey,i,new=1;
	while(new!=0){
		printf("Enter value to delete:-");
     	scanf("%d",&value);
     	hkey=value%size;
     	for(i=0;i<size;i++){
     		if(a[hkey+i*i]==value){
     			a[hkey+i*i]=-1;
			 }
		 }
		 printf("Enter 1 or 0:-");
		 scanf("%d",&new);
	}
	traverse(a);
}

int search(){
	int value,hkey,flag=0,i;
	printf("Enter value to search:-");
	scanf("%d",&value);
	hkey=value%size;
	for(i=0;i<size;i++){
		if(a[hkey+i*i]==value){
			flag=1;
			break;
		}
		else{
			flag=0;
		}
	}
	if(flag==1){
		printf("Search found at %d",hkey);
	}
	else{
		printf("Serach not found");
	}
	
}













