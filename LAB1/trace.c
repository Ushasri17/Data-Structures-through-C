#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
//trace of matrix;
int i,j,k,a[50][50],r,c,trace;
printf("Enter the number of rows:\n");
scanf("%d",&r);
printf("Enter the number of columns:\n");
scanf("%d",&c);
for(i=0;i<r;i++)

{printf("element-%d:",i+1);
    for(j=0;j<c;j++){
        //printf("element-%d:",i+1);
        scanf("%d",&a[i][j]);
    }
}
printf("matrix A is:\n");
for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        printf("%d",a[i][j]);
    }
    printf("\n");
}
for(i=0;i<r;i++){
    trace+=a[i][i];
}
printf("\n trace of the given matrix is %d.\n\n",trace);
}
