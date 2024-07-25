//sorting
#include<stdio.h>
#include<stdlib.h>
int i,n,a[50],j,low,high;

int main(){
				arr(a);
			   quicksort(a,0,n-1);
			   traverse(a);
			
}

int arr(int a[]){
	printf("Enter size of array:-");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter element:-");
		scanf("%d",&a[i]);
	}
	printf("Before sorting:-");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

int traverse(int a[]){
	printf("\n");
	printf("After sorting:-");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}


int swap(int *p,int *q){
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

int quicksort(int a[],int low,int high){
	if(low<high){
	  int PI=partition(a,low,high);	
	  quicksort(a,low,PI-1);
	  quicksort(a,PI+1,high);
	}
}

int partition(int a[],int low,int high){
	int pivot;
	pivot=a[high];
	i=low-1;
	for(j=low;j<high;j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
}

void mergesort(int a[],int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
//    	mid=low+(high-1)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void merge(int a[],int low,int mid,int high){
	int i,j,k,n1,n2;
	n1=mid+1-low;
	n2=high-mid;
	int l[n1],r[n2];
	for(i=0;i<n1;i++){
		l[i]=a[i+low];
	}
	for(j=0;j<n2;j++){
		r[j]=a[j+1+mid];
	}
	i=0;
    j=0;
	k=low;
	while(i<n1 && j<n2){
		if(l[i]<=r[j]){
			a[k++]=l[i++];
		}
		else{
			a[k++]=r[j++];
		}
	}
	while(i<n1){
		a[k++]=l[i++];
	}
	while(j<n2){
		a[k++]=r[j++];
	}
}

