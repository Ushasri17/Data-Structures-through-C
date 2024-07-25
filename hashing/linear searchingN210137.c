//Searching
#include<stdio.h>
void main(){
	int a[100],search,i,n,flag=0;
	printf("Enter number of elements:-");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter element:-");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\nEnter element to search:-");
	scanf("%d",&search);
	for(i=0;i<=n;i++){
		if(a[i]==search){
			flag=1;
			break;
		}
	}
	if(flag==1){
		printf("Search is found");
	}
	else{
		printf("Search is not found");
	}
}
