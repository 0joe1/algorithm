#include <stdio.h>

struct queue{
    int data[2000];
    int head;
    int tail;
};
struct stack{
    int data[10];
    int top; 
};
int book[9];
void init(struct queue* q)
{
    q->head = q->tail = 0;
    for (int i=0;i<6;i++)
        scanf("%d",&q->data[q->tail++]);
}
void play(struct queue* q,struct stack* s)
{
    int t=q->data[q->head++];
    if (book[t]) 
    {
        q->data[q->tail++]=t;
        while (s->data[s->top] != t)
        {
            book[s->data[s->top]]=0;
            q->data[q->tail++] = s->data[s->top];
            s->top--;
        }
        book[s->data[s->top]] = 0;
        q->data[q->tail] = s->data[s->top];
        q->tail++;
        s->top--;
    }
    else
    {
        s->top++;
        s->data[s->top] = t;
        book[t]=1;
    }
}

int main(void)
{
    struct queue heng,ha;
    struct stack desk;

    desk.top=0;
    init(&heng);init(&ha);
    while (heng.head<heng.tail && ha.head<ha.tail)
    {
        play(&heng,&desk);
        printf("小哼：");
        for (int i=heng.head;i<heng.tail;i++)  printf(" %d ",heng.data[i]);
        printf("\n");
        if (heng.head==heng.tail) break;
        play(&ha,&desk);
        printf("小哈：");
        for (int i=ha.head;i<ha.tail;i++)  printf(" %d ",ha.data[i]);
        printf("\n\n");
    }
    for (int i=0;i<desk.top;i++) printf("%d",desk.data[i]);
    if (heng.head==heng.tail) printf("小哈胜利");
    else printf("小哼胜利");
    return 0;
}