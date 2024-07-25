 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
     union un
    {
        char data;
        int x;
    }u;
    struct node *next;
}*top=NULL,*p,*temp,*y;
struct node *stack(char x)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->u.data=x;
    temp->next=NULL;
    if(top==NULL)
        top=temp;
    else
    {
        temp->next=top;
        top=temp;
    }
    return top;
}
struct node *pushi(int x)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->u.x=x;
    temp->next=NULL;
    if(top==NULL)
        top=temp;
    else
    {
        temp->next=top;
        top=temp;
    }
    return top;
}
char pop()
{
    char ch;
    if(top==NULL)
        printf("stack is empty\n");
    else
    {
        temp=top;
        top=top->next;
        temp->next=NULL;
        ch=temp->u.data;
        free(temp);
    }
    return ch;
}
int popi()
{
    int ch;
    if(top==NULL)
        printf("stack is empty\n");
    else
    {
        temp=top;
        top=top->next;
        temp->next=NULL;
        ch=temp->u.x;
        free(temp);
    }
    return ch;
}
char str[50],rs[50];
void in()
{
    printf("enter expression:");
    int i=0;
    do
    {   char x;
        scanf("%c",&x);
        if(x=='\n')
            break;
        str[i++]=x;
    } while(1);
}
void rev()
{
    int count=0,i,j;
    for(i=0;str[i]!='\0';i++)
        count++;
    for(i=count-1,j=0;i>=0;i--,j++)
        rs[j]=str[i];
}
int pri(char x)
{
    switch(x)
    {
        case ')':
            return 1;
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
        case '^':
            return 4;
            break;
    }
}
int value[50];
void evaluation(char op[])
{
    int i,a=0,b=0;
    for(i=0;op[i]!='\0';i++)
    {
        if(op[i]>='a' && op[i]<='z' || op[i]>='A' && op[i]<='Z')
        {
            printf("enter value of %c: ",op[i]);
            scanf("%d",&value[i]);
        }
    }
    for(i=0;op[i]!='\0';i++)
    {
        if(op[i]>='a' && op[i]<='z' || op[i]>='A' && op[i]<='Z')
            p=pushi(value[i]);
        else
        {
            a=popi();
            b=popi();
            switch(op[i])
            {
                case '+':
                    p=pushi(a+b);
                    break;
                case '-':
                    p=pushi(a-b);
                    break;
                case '*':
                    p=pushi(b*a);
                    break;
                case '%':
                    p=pushi(a%b);
                    break;
                case '/':
                    p=pushi(a/b);
                    break;
                case '^':
                    p=pushi(a^b);
                    break;
            }
        }
    }
    printf("result :%d\n",popi());
}
void main()
{
    in();
    rev();
    int i,j=0;
    char op[50],ors[50],z;
    for(i=0;rs[i]!='\0';i++)
    {
        if(rs[i]==')')
            y=stack(rs[i]);
        else if(rs[i]>='a' && rs[i]<='z' || rs[i]>='A' && rs[i]<='Z')
            op[j++]=rs[i];
        else if(rs[i]=='(')
        {
            while(top!=NULL && top->u.data!=')')
                op[j++]=pop();
            z=pop();
        }
        else
        {
            while(top!=NULL && pri(rs[i])<pri(top->u.data))
            {
                op[j++]=pop();
            }
            y=stack(rs[i]);
        }
    }
    while(top!=NULL)
    {
        op[j++]=pop();
    }
    int count=0;
    for(i=0;op[i]!='\0';i++)
        count++;
    for(i=count-1,j=0;i>=0;i--,j++)
        ors[j]=op[i];
    for(i=0;ors[i]!='\0';i++)
        printf("%c",ors[i]);
    printf("\n");
    int w;
    do
    {
        printf("enter values for variables:\n");
        evaluation(op);
        printf("enter 1 for another set of values:");
        scanf("%d",&w);
    }while(w==1);
} 