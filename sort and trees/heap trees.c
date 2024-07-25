//Max heap trees
#include<stdio.h>

int a[50],n,i;
void main(){
	int choice;
	do{
		printf("\n1.max heap\n2.Min heap\n3.HeapSort\n");
		printf("Enter your choice:-");
		scanf("%d",&choice);
		switch(choice){
			case 1:arr(a);
			maxheap(a,n);
			for(i=0;i<n;i++){
				printf("%d\t",a[i]);
			}
			break;
			case 2:arr(a);
			minheap(a,n);
			for(i=0;i<n;i++){
				printf("%d\t",a[i]);
			}
			break;
			case 3:arr(a);
			heapsort(a,n);
			break;
		}	
	}while(choice!=0);
}

int arr(int a[]){
	a[n];
	printf("Enter size of the array:-");
 	scanf("%d",&n);
 	for(i=0;i<n;i++){
 		printf("Enter element:-");
 		scanf("%d",&a[i]);
	 }
//	for(i=0;i<n;i++){
// 		printf("%d\t",a[i]);
//	 }
	 return a;
}
void maxheap(int a[],int n){
 	for(i=n/2-1;i>=0;i--){
 		heapify(a,n,i);
	 }
}

void heapify(int a[],int n,int i){
	int l,r,large;
	large=i;
	l=(2*i)+1;
	r=(2*i)+2;
	if(l<n && a[l]>a[large]){
		large=l;
	}
	if(r<n && a[r]>a[large]){
		large=r;
	}
	if(large!=i){
		swap(&a[i],&a[large]);
		heapify(a,n,large);
	}	
//	return a;
}

void swap(int *p,int *q){
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

void minheap(int a[],int n){
 	for(i=(n/2)-1;i>=0;i--){
 		heapifying(a,n,i);
	 }
}

void heapifying(int a[],int n,int i){
	int l,r,small;
	small=i;
	l=(2*i)+1;
	r=(2*i)+2;
	if(l<n && a[l]<a[small]){
		small=l;
	}
	if(r<n && a[r]<a[small]){
		small=r;
	}
	if(small!=i){
		swap(&a[i],&a[small]);
		heapify(a,n,small);
	}	
}

void heapsort(int a[],int n){
	for(i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}
	for(i=n-1;i>=0;i--){
		swap(&a[0],&a[i]);
		heapify(a,i,0);
	}
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}















