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
