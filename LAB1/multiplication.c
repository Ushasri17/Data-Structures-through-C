#include<stdio.h>
#include<stdlib.h>
int main(){
//multiplication of a matrix
int i,j,k,a[50][50],r1,c1,r2,c2,b[50][50];
printf("enter the number of rows:");
scanf("%d",&r1);
printf("enter the number of columns:");
scanf("%d",&c1);

for(i=0;i<r1;i++){
//    printf("element-%d:",i+1);
    for(j=0;j<c1;j++){
       printf("element-a[%d][%d]:",i,j);
        scanf("%d",&a[i][j]);
    }
}
printf("Display the matrix A:\n");
for(i=0;i<r1;i++){
    for(j=0;j<c1;j++){
        printf("%d\t",a[i][j]);
    }
    printf("\n");
}
printf("\nenter the data in B matrix:\n");
printf("enter number of rows: ");
scanf("%d",&r2);
printf("enter the number of columns:");
scanf("%d",&c2);

for(i=0;i<r2;i++){
          //  printf("element -%d:",i+1);
    for(j=0;j<c2;j++){
          
printf("element-a[%d][%d]:",i,j);
         scanf("%d",&b[i][j]);
    }

}
printf("Display the matrix B:\n");
for(i=0;i<r2;i++){
    for(j=0;j<c2;j++){
        printf("%d\t",b[i][j]);
    }
    printf("\n");
}
int r[50][50];
 
if(c1==r2){
    printf("resultant matrix is :\n");
for(i=0;i<r1;i++){
for(j=0;j<c2;j++){
    r[i][j]=0;
    for(k=0;k<r2;k++){
        r[i][j]+=(a[i][k]*b[k][j]);
    }
    printf("%d ",r[i][j]);
}
printf("\n");
}
  
}
else
printf("we cannot multiply the matrices.");


























}