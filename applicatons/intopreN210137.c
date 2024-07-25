//prefix ...
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char stack[100];
char output[100];
char infix[100];
int add[100];
int t=-1, id=0,k=-1;
int popi(){   
           return add[k--];
}
void pushi(int num){
      
       add[++k]=num;
}
int evaluation(char str[]){
 
    for(int i=0;str[i]!='\0';i++){
        char c=str[i];
        int num;
        if(isalpha(c)){
            printf("enter the value of %c:",c);
            scanf("%d",&num);
             pushi(num);
        }
        else{
            int result;
            switch(c){
                case '+':result=popi()+popi();
                         pushi(result);
                         break;
                case '-':result=popi()-popi();
                         pushi(result);
                         break;
                case '*':result=popi()*popi();
                         pushi(result);
                         break;
                case '%':result=popi()%popi();
                         pushi(result);
                         break;
                case '/':result=popi()/popi();
                         pushi(result);
                         break;    
            }

        }
    }
   
   
return add[k];
}
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
void push(char x){
    
        t=t+1;
        stack[t]=x;
    
}
char pop(){
    if(t==-1){
        printf("empty stack");
    }
    else{ 
        
           return stack[t--];}
}
void in()
{   
    printf("enter expression:");
    int i=0;
    do
    {   char x;
        scanf("%c",&x);
        if(x=='\n')
            break;
        infix[i++]=x;
    } while(1);
}
void evaluate(char str[]){
    int j;
do{
 int result=evaluation(str);
 printf("Result of the expression:%d",result);
 printf("\n");
 printf("enter 1 to continue:");
 scanf("%d",&j);
}while(j==1);

}
void main()
{     
    in();
    reverseString(infix);
    for(int i=0;infix[i]!='\0';i++){\
        char c=infix[i];
        if(infix[i]==')'){
            push(infix[i]);
        }
           else if(isalnum(c)){
            output[id++]=c;
        }
        else if(infix[i]=='(')
        {
            while(stack[t]!=')'&& t!=-1){
           
             output[id++]=pop();  
            }
            pop();
        }
        else if(prior(infix[i])>=prior(stack[t])){
            push(infix[i]);
        }
        else if(prior(infix[i])<prior(stack[t])){
            while(prior(infix[i])<prior(stack[t]))
                output[id++]=pop();
            push(c);
        }
        else{
            printf("entered the wrong expression.");
        }
    }
    while(t!=-1)
    output[id++]=pop();
    char str[100];
    strcpy(str,output);
    reverseString(output);
    printf("preifx of a expression is :");
    puts(output);
    evaluate(str);
}