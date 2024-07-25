#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *pre;
}*start=NULL,*temp,*p,*end;
struct node *creation(struct node *start)
{
    printf("enter no.of nodes to be creating:");
    int n,i;
    scanf("%d",&n);
    start=NULL;
    for(i=0;i<n;i++)
    {
        int x;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d",&x);
        temp->data=x;
        temp->next=NULL;
        temp->pre=NULL;
        if(start==NULL)
        {
            start=temp;
            start->next=start;
            start->pre=start;
            end=start;
        }
        else
        {
            temp->pre=end;
            end->next=temp;
            end=end->next;
            end->next=start;
            start->pre=end;
        }
    }
    return start;
}
void traverse(struct node *start)
{
    if(start==NULL)
        printf("linked list is empty\n");
    else
    {
        p=start;
        do
        {
            printf("%d  ",p->data);
            p=p->next;
        }while(p!=start);
    }
    printf("\n");
}
void traversebw(struct node *start)
{
    if(start==NULL)
        printf("linked list is empty\n");
    else
    {
        p=end;
        do
        {
            printf("%d  ",p->data);
            p=p->pre;
        }while(p!=end);
    }
}
void insertionatbegging()
{
    temp=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("enter data:");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    temp->pre=NULL;
    if(start==NULL)
    {
        start=temp;
        start->next=start;
        start->pre=start;
        end=start;
    }
    else
    {
        temp->next=start;
        start->pre=temp;
        start=temp;
        start->pre=end;
        end->next=start;
    }
}
void insertionatend()
{
    temp=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("enter data:");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    temp->pre=NULL;
    if(start==NULL)
    {
        start=temp;
        start->next=start;
        start->pre=start;
        end=start;
    }
    else
    {
        end->next=temp;
        temp->pre=end;
        end=temp;
        end->next=start;
        start->pre=end;
    }
}
void insertion()
{
    int pos,k,count=1;
    temp=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("enter data:");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    temp->pre=NULL;
    if(start==NULL)
    {
        start=temp;
        start->next=start;
        start->pre=start;
        end=start;
    }
    else
    {
        printf("enter position:");
        scanf("%d",&pos);
        p=start;
        while(p->next!=start)
        {
            count++;
            p=p->next;
        }
        if(pos>0 && pos<=count+1)
        {
            if(pos==1)
                insertionatbegging();
            else if(pos==count+1)
                insertionatend();
            else
            {
                p=start;
                for(k=1;k<pos-1;k++)
                    p=p->next;
                temp->next=p->next;
                p->next=temp;
                temp->pre=p;
                temp->next->pre=temp;
            }
        }
        else
        {
            printf("enter invalid no.\n");
        }
    }
}
void deletionatbeg()
{
    if(start==NULL)
        printf("linked list is empty\n");
    else if(start->next==start)
    {
        temp=start;
        temp->next=NULL;
        temp->pre=NULL;
        free(temp);
    }
    else
    {
        temp=start;
        start=start->next;
        start->pre=end;
        end->next=start;
        temp->next=NULL;
        temp->pre=NULL;
        free(temp);
    }
}
void deletionatend()
{
    if(start==NULL)
        printf("linked list is empty\n");
    else if(start->next==start)
    {
        temp=start;
        temp->next=NULL;
        temp->pre=NULL;
        free(temp);
    }
    else
    {
        p=start;
        while(p->next->next!=start){
            p=p->next;
        }
        temp=end;
        p->next=start;
        start->pre=p;
        end=p;
        temp->next=temp->pre=NULL;
        free(temp);
    }
}
void deletion()
{
    int pos,count=1,k;
    if(start==NULL)
        printf("linked list is empty\n");
    else if(start->next==start)
    {
        temp=start;
        temp->next=NULL;
        temp->pre=NULL;
        free(temp);
    }
    else
    {
        printf("enter position:");
        scanf("%d",&pos);
        p=start;
        while(p->next!=start)
        {
            count++;
            p=p->next;
        }
        if(pos>0 && pos<=count)
        {
            if(pos==1)
                deletionatbeg();
            else if(pos==count)
                deletionatend();
            else
            {
                p=start;
                for(k=1;k<pos-1;k++)
                    p=p->next;
                temp=p->next;
                p->next=temp->next;
                temp->next=NULL;
                temp->pre=NULL;
                p->next->pre=p;
                free(temp);
            }
        }
        else
        {
            printf("enter invalid no.\n");
        }
    }
}
void search()
{
    if(start==NULL)
        printf("linked list is empty");
    else
    {
        printf("enter data to be search:");
        int n,count=0,c=0;
        scanf("%d",&n);
        p=start;
        do
        {
            count++;
            if(p->data==n)
            {
                c=1;
                break;
            }
            p=p->next;
        }while(p!=start);
        if(c==0)
            printf("search is not found");
        else
            printf("search is found in %d node",count);
    }
}
void sort()
{
    struct node *temp1;
    int i;
    if(start==NULL)
        printf("linked list is empty\n");
    else
    {
        temp=start;
        do
        {
            for(temp1=temp->next;temp1!=start;temp1=temp1->next)
            {
                if(temp->data>temp1->data)
                {
                    i=temp->data;
                    temp->data=temp1->data;
                    temp1->data=i;
                }
            }
            temp=temp->next;
        }while(temp!=start);
    }
}
void reverse()
{
    struct node *p1,*p2,*p3;
    if(start==NULL)
        printf("linked list is empty\n");
    else if(start->next==start)
        printf("linked list consist of one node");
    else
    {
        p1=start;
        p2=p1->next;
        p3=p2->next;
        p2->next=p1;
        p1->pre=p2;
        p1->next=end;
        while(p3!=start)
        {
            p1=p2;
            p2=p3;
            p3=p2->next;
            p2->next=p1;
            p1->pre=p2;
        }
        p2->pre=start;
        end=start;
        start=p2;
    }
}
void revrec(struct node *p1,struct node *p2)
{
    if(start==NULL)
        printf("linked list is empty\n");
    else
    {
        struct node *p3;
        p3=p2->next;
        p2->next=p1;
        p1->pre=p2;
        if(p1==start)
            p1->next=end;
        if(p3!=start)
        {
            return revrec(p2,p3);
        }
        p2->pre=start;
        end=start;
        start=p2;
    }
}
void concate()
{
    struct node *start1,*start2;
    start1=creation(start1);
    start2=creation(start2);
    p=start1;
    while(p->next!=start1)
        p=p->next;
    p->next=start2;
    start2->pre=p;
    p=start2;
    while(p->next!=start2)
        p=p->next;
    end=p;
    end->next=start1;
    start1->pre=end;
    traverse(start1);
}
void delelement()
{
    int x;
    printf("enter delete element:");
    scanf("%d",&x);
    if(start==NULL)
        printf("linked list is empty");
    else if(start->next==start)
    {
        if(start->data==x)
        {
            temp=start;
            start=NULL;
            temp->next=NULL;
            temp->pre=NULL;
            free(temp);
        }
    }
    else
    {
        p=start;
        while(p->next!=start)
        {
            if(p->next->data==x)
            {
                temp=p->next;
                p->next=temp->next;
                p->next->pre=p;
                temp->next=NULL;
                temp->pre=NULL;
                free(temp);
            }
            else
                p=p->next;
        }
        end=p;
        p=start;
        if(p->data==x)
        {
            temp=start;
            start=start->next;
            end->next=start;
            start->pre=end;
            temp->next=NULL;
            temp->pre=NULL;
            free(temp);
        }
    }
}
void rmvdup()
{
    struct node *temp1,*temp2;
    temp1=start;
    do
    {
        for(temp=temp1;temp->next!=start;)
        {
            if(temp->next->data==temp1->data)
            {
                p=temp->next;
                temp->next=p->next;
                temp->next->pre=temp;
                p->next=NULL;
                p->pre=NULL;
                free(p);
            }
            else
            {
                temp=temp->next;
            }
        }
        temp1=temp1->next;
    }while(temp1!=start);
}
void main()
{
    int p=0;
            printf("enter no. based on these: \n1.creation \n2.traversing \n3.insertion \n4.deletion \n5.searching \n6.soarting \n7.reverse \n8.concatination \n9.delete duplicants \n10.delete element \n11.traverse backwards \n");
    do
    {
//        printf("enter no. based on these: \n1.creation \n2.traversing \n3.insertion \n4.deletion \n5.searching \n6.soarting \n7.reverse \n8.concatination \n9.delete duplicants \n10.delete element \n11.traverse backwards \n");
        int a,n;
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                start=creation(start);
                break;
            case 2:
                traverse(start);
                break;
            case 3:
                printf("enter no. based on these: \n1.at beginning \n2.at end \n3.at specified position");
                int b;
                scanf("%d",&b);
                switch(b)
                {
                    case 1:
                        insertionatbegging();
                        break;
                    case 2:
                        insertionatend();
                        break;
                    case 3:
                        insertion();
                        break;
                    default:
                        printf("enter invalid no.");
                }
                break;
            case 4:
                printf("enter no. based on these: \n1.at beginning \n2.at end \n3.at specified position");
                int z;
                scanf("%d",&z);
                switch(z)
                {
                    case 1:
                        deletionatbeg();
                        break;
                    case 2:
                        deletionatend();
                        break;
                    case 3:
                        deletion();
                        break;
                    default:
                        printf("enter invalid no.\n");
                }
                break;
            case 5:
                search();
                break;
            case 6:
                sort();
                break;
            case 7:
                reverse();
                break;
            case 8:
                concate();
                break;
            case 9:
                rmvdup();
                break;
            case 10:
                delelement();
                break;
            case 11:
                traversebw(start);
                break;
            default:
                printf("enter invalid no.\n");
        }
        printf("if u want to do operation enter positive no.");
        scanf("%d",&n);
        p=n;
    }while(p>0);
    
    start=creation(start);
    revrec(start,start->next);
    traverse(start);

}