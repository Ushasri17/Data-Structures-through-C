 #include<stdio.h>
#include<stdlib.h>
struct node
{
    union un
    {
        char data;
        int x;
    }u;
    struct node *nxt;
}*top=NULL,*temp,*p;
struct node *push(char ch)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->u.data=ch;
    temp->nxt=NULL;
    if(top==NULL)
        top=temp;
    else
    {
        temp->nxt=top;
        top=temp;
    }
    return top;
}
struct node *pushi(int ch)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->u.x=ch;
    temp->nxt=NULL;
    if(top==NULL)
        top=temp;
    else
    {
        temp->nxt=top;
        top=temp;
    }
    return top;
}
char pop()
{
    char n;
    if(top==NULL)
        printf("stack is empty\n");
    else
    {
        temp=top;
        n=temp->u.data;
        top=top->nxt;
        temp->nxt=NULL;
        free(temp);
    }
    return n;
}
int popi()
{
    int n;
    if(top==NULL)
        return -1;
    else
    {
        temp=top;
        n=temp->u.x;
        top=top->nxt;
        temp->nxt=NULL;
        free(temp);
    }
    return n;
}
int pri(char x)
{
    switch(x)
    {
        case '(':
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
int value[50]={0};
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
            if(a!=-1 && b!=-1)
            {
                switch(op[i])
                {
                    case '+':
                        p=pushi(b+a);
                        break;
                    case '-':
                        p=pushi(b-a);
                        break;
                    case '*':
                        p=pushi(b*a);
                        break;
                    case '%':
                        p=pushi(b%a);
                        break;
                    case '/':
                        p=pushi(b/a);
                        break;
                    case '^':
                        p=pushi(b^a);
                        break;
                }
            }
            else
                break;
        }
    }
    if(b==-1)
        printf("result:%d\n",a);
    else
        printf("result :%d\n",popi());
}
void main()
{
    printf("enter expression:");
    char str[50],op[50],m;
    int i=0,j=0;
    do
    {
        char x;
        scanf("%c",&x);
        if(x=='\n')
            break;
        str[i]=x;
        i++;
    } while(1);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(')
            p=push(str[i]);
        else if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z')
            op[j++]=str[i];
        else if(str[i]==')')
        {
            while(top->u.data!='(')
                op[j++]=pop();
            m=pop();
        }
        else
        {   while(top!=NULL &&  pri(str[i])<=pri(top->u.data))
                op[j++]=pop();
            p=push(str[i]);
        }
    }
    while(top!=NULL)
    {
        m=pop();
        op[j++]=m;
    }
    for(i=0;op[i]!='\0';i++)
    {
        printf("%c",op[i]);
    }
    printf("\n");
    int z;
    do
    {
        printf("enter values for variables:\n");
        evaluation(op);
        printf("enter 1 for another set of values:");
        scanf("%d",&z);
    }while(z==1);


}