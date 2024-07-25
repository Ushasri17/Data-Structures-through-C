//sorting
#include<stdio.h>
#include<stdlib.h>
int i,n,a[50],j,low,high;

int main(){
	int choice;
	do{
		printf("\n1.Insertion sort\n2.Selection sort\n3.Quick sort\n4.Mergesort\n5.Countingsort\n6.Radixsort\n7.Shellsorting\n");
		printf("Enter your choice:-");
		scanf("%d",&choice);
		switch(choice){
			case 1:arr(a);
			      insertion(a,n);
			break;
			case 2:arr(a);
		     	selection_sort(a,n);
			break;
			case 3:arr(a);
			   quicksort(a,0,n-1);
			   traverse(a);
			break;
			case 4:arr(a);
			   mergesort(a,0,n-1);
			   traverse(a);
			break;
			case 5:arr(a);
			   count_sort(a,n);
			   traverse(a);
			break;
			case 6:arr(a);
			   radix_sort(a,n);
		       traverse(a);
			break;	
			case 7:arr(a);
		       shell_sort(a,n);
			   traverse(a);
			break;
		}
	}while(choice!=0);
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

int traverse(){
	printf("\n");
	printf("After sorting:-");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

int  insertion(int a[],int n){
	int j,key;
	for(i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	traverse(a);
}

int selection_sort(int a[],int n){
	int min_index=0;
	for(i=0;i<n-1;i++){
		min_index=i;
		for(j=i+1;j<n;j++){
			if(a[min_index]>a[j]){
				min_index=j;
			}
		}
		swap(&a[i],&a[min_index]);
	}
	traverse(a);
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

int count_sort(int a[],int n){
	int output[n],max;
	max=getmax(a,n);
	int count[max+1];
	int i;
	for(i=0;i<=max;i++){
		count[i]=0;
	}
	for(i=0;i<n;i++){
		count[a[i]]++;
	}
	for(i=1;i<=max;i++){
	    count[i]=count[i]+count[i-1];	
	}
	for(i=n-1;i>=0;i--){
		output[count[a[i]]-1]=a[i];
		count[a[i]]--;
	}
	for(i=0;i<n;i++){
		a[i]=output[i];
	}
}

int getmax(int a[],int n){
	int b;
	b=a[0];
	for(i=0;i<n;i++){
		if(a[i]>b){
			b=a[i];
		}
	}
	return b;
}

int radix_sort(int a[],int n){
	int max,place=1;
	max=getmax(a,n);
	for(place=1;max/place>0;place*=10){
		counting(a,n,place);
	}
}

int counting(int a[],int n,int place){
	int output[n];
	int max=(a[0]/place)%10;
     for(i=0;i<n;i++){
     	if((a[i]/place)%10>max){
     		max=(a[i]/place)%10;
		 }
	 }
   int count[max];
   for(i=0;i<=max;i++){
   	   count[i]=0;
   }
   for(i=0;i<n;i++){
   	count[(a[i]/place)%10]++;
   }
   for(i=1;i<=max;i++){
   	count[i]+=count[i-1];
   }
   for(i=n-1;i>=0;i--){
   	output[count[(a[i]/place)%10]-1]=a[i];
   	count[(a[i]/place)%10]--;
   }
   for(i=0;i<n;i++){
   	a[i]=output[i];
   }	  
}


int shell_sort(int a[],int n){
	int interval,temp;
	for(interval=n/2;interval>0;interval/=2){
		for(i=interval;i<n;i++){
			temp=a[i];
			for(j=i;j>=interval && a[j-interval]>temp;j-=interval){
				a[j]=a[j-interval];
			}
			a[j]=temp;
		}
	}
}






