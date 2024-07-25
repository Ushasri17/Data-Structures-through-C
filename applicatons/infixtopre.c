#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
int t=-1;
char  prefix[MAX];
 int index=0;
char stack[50];
char output[50];
int prior(char ch){
    switch(ch){
        case '#':return 0;
                 break;
        case ')':return 1;
                 break;
        case '+':
        case '-':
                return 2;
                break;
        case '*':
        case '%':
        case '/':
                return 3;
                break;
    } 
    }
void push(char x){

    if(t>=MAX-1){
            printf("stack is full.");
     }
     else{
        t=t+1;
        stack[t]=x;
     }
     
  } 
  
void reverseString(char* str) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main(){
    printf("Enter the expresstion:\n");
    char infix[40],str[50];
    scanf("%s",(infix));
    printf("%s",infix);
    reverseString(infix);
   // strcpy(str,infix);
    printf("\nreverse of a string:%s\n",infix);
    for(int i=0;i<strlen(infix);i++){
        if(infix[i]==')'){
            push(infix[i]);

        }
        else if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='0'&&infix[i]<='9')){
           output[index]=infix[i];
           index++;
        }
        else if(prior(infix[i]>=prior(prefix[t]))){
            push(infix[i]);
        }
        else if(prior(infix[i])<prior(prefix[t])){
            output[index++]=infix[i];
            pop(infix[i]);
        }
        else{
            printf("entered the wrong expression.");
        }
    }
    for(int j=0;j<5;j++){
        printf("%c",output[j]);
    }
    for(int k=0;k<5;k++){
        printf("%c",stack[k]);
    }
    printf("\n");
        
}
     



