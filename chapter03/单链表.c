#include <stdio.h>
#include <stdlib.h> // 添加此行以声明 free 和 malloc 函数
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

// 初始化单链表
int InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    if (*L == NULL)
        return ERROR; // 检查内存分配是否成功
    (*L)->next = NULL;

    LinkList tail = *L; // 使用尾插法优化插入过程
    for (int i = 0; i < 10; i++)
    {
        LinkList newNode = (LinkList)malloc(sizeof(Node));
        if (newNode == NULL)
            return ERROR; // 检查内存分配是否成功
        newNode->data = i;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

    return OK;
}

// 获取第i个元素
Status GetElem(LinkList L, int i, ElemType *e)
{
    if (L == NULL || i <= 0)
        return ERROR; // 检查输入合法性
    int j = 1;
    LinkList p = L->next;

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

// 插入元素到第i个位置
Status ListInsert(LinkList *L, int i, ElemType e)
{
    if (L == NULL || i <= 0)
        return ERROR; // 检查输入合法性
    int j = 1;
    LinkList p = *L;

    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if (!p || j > i)
        return ERROR;

    LinkList s = (LinkList)malloc(sizeof(Node));
    if (s == NULL)
        return ERROR; // 检查内存分配是否成功
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 删除第i个元素
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    if (L == NULL || i <= 0)
        return ERROR; // 检查输入合法性
    int j = 1;
    LinkList p = *L;

    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }

    if (!(p->next) || j > i)
        return ERROR;

    LinkList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q); // 释放节点内存
    return OK;
}

// 主函数
int main()
{
    LinkList L;
    if (InitList(&L) != OK)
    {
        printf("初始化失败\n");
        return -1;
    }

    for (int i = 1; i <= 10; i++) // 注意：GetElem 的索引从1开始
    {
        ElemType e;
        if (GetElem(L, i, &e) == OK)
            printf("%d ", e);
    }
    printf("\n");

    return 0;
}