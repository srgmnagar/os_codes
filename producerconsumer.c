#include<stdio.h>
#include<stdlib.h>
#define n 8
int buffer[n],in=-1,out=-1,s=1,empty=n,full=0,itemp,itemc;

int wait(int s)
{
    while(s<0)
    s--;
    return s;
}

int signal(int s)
{
    s++;
    return s;
}

void producer()
{
    s=wait(s);
    itemp=rand()%100;
    if(full==n)
    {
        printf("Buffer full");
    }
    else if(in==-1 && out==-1)
    {
        empty = wait(empty);
        in=0;
        out=0;
        buffer[in]=itemp;
        printf("item produced is %d",itemp);
        full=signal(full);
    }
    else
    {
        empty = wait(empty);
        in=(in+1)%n;
        buffer[in]=itemp;
         printf("item produced is %d",itemp);
        full=signal(full);
    }
    s=signal(s);
}

void consumer()
{
   s=wait(s);
   if(in==-1 && out==-1)
   {
       printf("Buffer empty");
   }
   else if (in==out)
   {
        full=wait(full);
        itemc=buffer[out];
        buffer[out]=-1;
        in=out=-1;
        printf("Item consumed is %d\n",itemc);
        empty=signal(empty);
   }
   else
   {
        full=wait(full);
        itemc=buffer[out];
        buffer[out]=-1;
        out = (out+1)%n;
        printf("Item consumed is %d\n",itemc);
        empty=signal(empty);
   }
   s=signal(s);
}

void display()
{   if(in==-1)
{
    printf("Buffer empty");
}
else
{
    for(int i=0;i<n;i++)
    {
        if(buffer[i] == -1)
        printf("-\t");
        else
        printf("%d\t",buffer[i]);
    }
    printf("\n");    
}
   
}


void main()
{
    int ch=4;
    for(int i=0;i<n;i++)
    buffer[i]=-1;
    do
    {
        // printf("\ns=%d empty=%d full=%d\n",s,empty,full);
        printf("Main Menu\n");
        printf("1.produce\n");
        printf("2.consume\n");
        printf("3.display\n");
        printf("4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            producer();
            break;
            case 2:
            consumer();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("Thank you");
            break;
            default:
            printf("Invalid");
        }
       
        
    }
     while(ch!=4);
}
