#include<stdio.h>
int hcf(int n1, int n2) {
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else
        return n1;
}
 int main(){/*
int x,y,i,gcd;
printf("enter the two numbers :");
scanf("%d%d",&x,&y);
for(i=1;i<=x&&i<=y;i++){
if(x%i==0 && y%i==0){
    gcd=i;
}
   }
   printf("gcd of two numbs is :%d\n",gcd);*/
    int n1, n2;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    printf("G.C.D of %d and %d is %d.", n1, n2, hcf(n1, n2));
    return 0;
}

 
 
