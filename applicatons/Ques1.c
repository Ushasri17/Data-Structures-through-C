#include<stdio.h>
#include<math.h>

int arr[50],n,i;
void sortArray(int arr[],int len){
//	int len=sizeof(arr)/sizeof(arr[0]);
	int j=0,temp;
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(arr[i]<arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int LinearSearchOp(int a[],int n,int target){
	int closest[15]={0};
	int dif;
	for(i=0;i<n;i++){
		dif = target-a[i];
		if(dif<target){
			closest[i]=a[i];
		}else if(dif>target){
			closest[i]=a[i];
		}
	}
	sortArray(closest,15);
	int key=0,c=0,d=0,ret1=0,ret2=0;
	for(i=0;i<15;i++){
		if(closest[i]-target>=0){
		c++;	
		}	
	}
	
	for(i=14;i>=0;i--){
		if(target-closest[i]>=0){
		d++;	
		}	
	}
	
	if((closest[c]-target)<(closest[0]-target))		ret1= closest[c];	else ret1 = 0;
	if((target-closest[14])>target-closest[d])		ret2= closest[d];	else ret2 = 14;
	if((ret1-target)>(target-ret2))		return ret2;
	else return ret1;

}


int main(){
	int len ,target;
	printf("Enter size of array");
	scanf("%d",&len);
	for(i=0;i<len;i++){
		printf("Enter element:-");
		scanf("%d",&arr[i]);
	}
	printf("Enter a target to get closest value");
	scanf("%d",&target);
	int res  = LinearSearchOp(arr,len,target);
	printf("\nThe  closest value to the target is %d ",res);
	
}