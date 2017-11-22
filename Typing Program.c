#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct word
{
    char text;
    struct word *next, *prev;
}word;
word *Kepala=NULL,*Ekor=NULL,*temp=NULL,*gerak=NULL;

void add()
{
    temp=(word*)malloc(sizeof(word));
    if(kepala!=NULL)
    {
        if(gerak!=Ekor)
        {
            temp->next=gerak->next;
            temp->prev=gerak;
            gerak->next->prev=temp;
            gerak->next=temp;
            gerak=gerak->next;
        }
        else
        {
            gerak->next=temp;
            temp->prev=gerak;
            temp->next=NULL;
            gerak=gerak->next;
            Ekor=gerak;
        }
    }
    else
    {
        Kepala=temp;
        Kepala->next=NULL;
        Kepala->prev=NULL;
        Ekor=temp;
        gerak=temp;
    }
    printf("Add : ");
    scanf("%s",&gerak->text);
}

void del()
{
    if(head==tail)
    {
        free(head);
        Kepala=NULL;
        Ekor=NULL;
        gerak=NULL;
    }
    else if(gerak==Kepala)
    {
        gerak=gerak->next;
        gerak->prev=NULL;
        free(Kepala);
        Kepala=gerak;
    }
    else if(gerak==Ekor)
    {
        gerak=gerak->prev;
        gerak->next=NULL;
        free(Ekor);
        Ekor=gerak;
    }
    else
    {
        temp=gerak->prev;
        gerak=gerak->next;
        temp->next=gerak;
        free(gerak->prev);
        gerak->prev=temp;
    }
}
void sleft()
{
    if(gerak->prev!=NULL)
        gerak=gerak->prev;
}
void sright()
{
    if(gerak->next!=NULL)
        gerak=gerak->next;
}
void view()
{
    temp=NULL;
    if(Kepala!=NULL)
    {
        temp=Kepala;
        if(gerak==Kepala&&gerak==Ekor)
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
