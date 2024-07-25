
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    struct student{
      char id[50];
      char name[50];
      int roll;
      char sec[50];
      char phone[50];

    }s[50];
int n,i;
printf("enter the number of students:");
scanf("%d",&n);
printf("enter the details in the following order:\n");
//printf("1.ID\n2.NAME\n3.ROLL\n4.CLASS\n5.PHONE\n");
for(i=0;i<n;i++){
printf("1.ID\n2.NAME\n3.ROLL\n4.CLASS\n5.PHONE\n");

scanf("%s %s %d %s %s",s[i].id,s[i].name,&s[i].roll,s[i].sec,s[i].phone);
}
for(i=0;i<n;i++){
    printf("\nstudent ID:%s\nstudent Name:%s\nstudent roll:%d\nclass:%s\nphone:%s\n\n",s[i].id,s[i].name,s[i].roll,s[i].sec,s[i].phone);
}
}
