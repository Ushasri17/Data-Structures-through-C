//double hashing
#include<stdio.h>
#include<stdlib.h>
#define size 7

int a[size];
int p;

void main(){
	initial();
	int choice;
	do{
		printf("\n1.Insertion\n2.Delete\n3.Search\n");
		printf("Enter your choice:-");
		scanf("%d",&choice);
		switch(choice){
			case 1://initial();
			insert();
			break;
			case 2:deletion();
			break;
			case 3:search();
			break;
		}
	}while(choice!=0);
}

void insert(){
	int value,hkey1,hkey2,i,new=1;
    while(new!=0){
    printf("Enter value:-");
	scanf("%d",&value);
	hkey1=value%size;
	hkey2=getpm()-(value%getpm());
	for(i=0;i<size;i++){
		if(a[(hkey1+i*hkey2)%size]==-1){
			a[(hkey1+i*hkey2)%size]=value;
			break;
		}
	}
	if(i==size){
		printf("Hash table is full");
	}
	printf("Enter 1 or 0:-");
	scanf("%d",&new);
  }
  display();
}

int getpm(){
	int i,j,c=0;
	for(i=size;i>=0;i--){
		c=0;
		for(j=1;j<=i;j++){
			if(i%j==0){
				c++;
			}
		}
		if(c==2){
			p=i;
			break;
		}
	}
}

void display(){
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

void initial(){
	int i;
	for(i=0;i<size;i++){
		a[i]=-1;
	}
}

void deletion(){
	int value,i,hkey1,hkey2,new=1;
	while(new!=0){
		printf("Enter value to delete:-");
		scanf("%d",&value);
		hkey1=value%size;
	    hkey2=getpm()-(value%getpm());
		for(i=0;i<size;i++){
		if(a[(hkey1+i*hkey2)%size]==value){
			a[(hkey1+i*hkey2)%size]=-1;
			break;
		}
	}
	printf("Enter 1 or 0:-");
	scanf("%d",&new);
	}
	display();
}

void search(){
	int value,i,hkey1,hkey2,flag=0;
	printf("Enter value to search:-");
	scanf("%d",&value);
	hkey1=value%size;
	hkey2=getpm()-(value%getpm());
	for(i=0;i<size;i++){
		if(a[(hkey1+i*hkey2)%size]==value){
		flag=1;
		break;
	}
	else{
		flag=0;
	}
  }	
  if(flag==1){
  	printf("search found at %d",hkey1);
  }
  else{
  	printf("Search not found");
  }
  
}

















