#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
// 线性表的单链表结点定义
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
// 线性表的单链表
typedef struct Node *LinkList;

int InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    for (int i = 0; i < 10; i++)
    {
        (*L)->next = (LinkList)malloc(sizeof(Node));
        (*L)->next->data = i;
        (*L)->next->next = NULL;
        *L = (*L)->next;
    }

    return OK;
}

// 获取第i个元素
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;
    p = L->next;
    j = 1; // 计数器

    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if (!p || j > i)
        return ERROR; // 找不到第i个元素

    *e = p->data;
    return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i)
        return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

int main()
{
    LinkList L;
    InitList(&L);

    for (int i = 0; i < 10; i++)
    {
        ElemType e;
        GetElem(L, i, &e);
        printf("%d ", e);
    }
    return 0;
}