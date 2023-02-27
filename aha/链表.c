#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* next;
};

int main(void)
{
    struct node *head,*p,*q,*t;
    head=NULL;
    for (int i=0;i<6;i++)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->data = i;
        p->next = NULL;

        if (head==NULL){
            head=p;
        }
        else{
            q->next=p;
        }
        q=p;
    }
    t=head;
    while (t != NULL)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->data=666;
        if (t->data == 3)
        {
            p->next=t->next;
            t->next=p;
            break;
        }
        t=t->next;
    }
    
    
    t=head;
    while (t != NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    return 0;
}