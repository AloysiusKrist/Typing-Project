#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct word
{
    char text;
    struct word *next, *prev;
}word;
word *head=NULL,*tail=NULL,*temp=NULL,*act=NULL;

void add()
{
    temp=(word*)malloc(sizeof(word));
    if(head!=NULL)
    {
        if(act!=tail)
        {
            temp->next=act->next;
            temp->prev=act;
            act->next->prev=temp;
            act->next=temp;
            act=act->next;
        }
        else
        {
            act->next=temp;
            temp->prev=act;
            temp->next=NULL;
            act=act->next;
            tail=act;
        }
    }
    else
    {
        head=temp;
        head->next=NULL;
        head->prev=NULL;
        tail=temp;
        act=temp;
    }
    printf("Add : ");
    scanf("%s",&act->text);
}

void del()
{
    if(head==tail)
    {
        free(head);
        head=NULL;
        tail=NULL;
        act=NULL;
    }
    else if(act==head)
    {
        act=act->next;
        act->prev=NULL;
        free(head);
        head=act;
    }
    else if(act==tail)
    {
        act=act->prev;
        act->next=NULL;
        free(tail);
        tail=act;
    }
    else
    {
        temp=act->prev;
        act=act->next;
        temp->next=act;
        free(act->prev);
        act->prev=temp;
    }
}
void sleft()
{
    if(act->prev!=NULL)
        act=act->prev;
}
void sright()
{
    if(act->next!=NULL)
        act=act->next;
}
void view()
{
    temp=NULL;
    if(head!=NULL)
    {
        temp=head;
        if(act==head&&act==tail)
            printf("%c",temp->text);
        else
        {
            while(temp!=NULL)
            {
                printf("%c",temp->text);
                temp=temp->next;
            }
        }
    }
}

int main()
{
    int p,n,i,a=0;
    pst:
    system("cls");
    printf("input kapasitas input : ");
    scanf("%d",&n);
    if(n<=0)
    {
        goto pst;
    }
    for(i=n;i>=0;i--)
    {
        zonk:
        system("cls");
        if(i!=0)
        printf("\t<");
        if(i==0)
        printf("Your final word : ");
        view();
        if(i!=0)
        printf(">");
        if(i==0)
        {
            printf("\nWith length (per char) : %d",a);
            printf("\n\nFinished\n");
            getch();
            return 0;
        }
        printf("\n\n(%d)",i);
        printf("\n\nPilih:");
        printf("\n  1.Add");
        printf("\n  2.Delete");
        printf("\n  3.Shift Left");
        printf("\n  4.Shift Right");
        printf("\n  5.Exit\n");
        scanf("%d",&p);
        switch(p)
        {
            case 1: add(); a++;
            break;
            case 2:
                {
                    del();
                    if(a>0)
                        a--;
                }
            break;
            case 3: sleft();
            break;
            case 4: sright();
            break;
            case 5: i=0; goto zonk;
            break;
            default: goto zonk;
            break;
        }
    }
}
