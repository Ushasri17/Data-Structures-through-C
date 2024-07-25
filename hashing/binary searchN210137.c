#include<stdio.h>
#include<stdlib.h>
void main(){
    int a[5]={1,2,3,4,5};
    int l=0,h=4;

    int mid,x;
    printf("enter the element to be searched:");
    scanf("%d",&x);
    while(l<=h){
        mid=(l+h)/2;
        if(a[mid]==x)
        {
            printf("element is found.\n");
            break;
        }
         else if(a[mid]>=x){
            h=mid-1;
         }
         else if(a[mid]<=x){
         l=mid+1;
         }
         else{
            
            printf("element not found.");
         }
    }
    
}



























/*
// C program to implement iterative Binary Search
#include <stdio.h>

// An iterative binary search function.
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// If we reach here, then element was not present
	return -1;
}

// Driver code
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? printf("Element is not present"
							" in array")
				: printf("Element is present at "
							"index %d",
							result);
	return 0;
}
*/