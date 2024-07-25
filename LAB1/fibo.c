1  #include<stdio.h>
#include<stdlib.h>

int fibo(int term){
 static int sum=0,a=0,b=1;
 if(term!=0){
 sum=a+b;
 a=b;
 b=sum;
 printf("%d ",sum);
 fibo(term-1);

 }


}
int main(){
 int term;
 printf("ente the number of terms:\n");
 scanf("%d",&term);
 printf("%d %d ",0,1);
 fibo(term-2);

}
