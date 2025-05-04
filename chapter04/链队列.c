#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int QElemType;
typedef struct // 结点结构
{
  QElemType data;
  struct QNode *next;
} QNode, *QueuePtr;

typedef struct // 链表结构
{
  QueuePtr front, rear;
} LinkQueue;

// 入队
Status EnQueue(LinkQueue *Q, QElemType e)
{
  QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
  if (!p) // 存储分配失败
    return ERROR;

  p->data = e;
  p->next = NULL;

  Q->rear->next = p; // 把拥有元素 e 的新结点 p赋值给原队尾结点的后继
  Q->rear = p;       // 把 p 设置为队尾结点

  return OK;
}

// 出队
Status DeQueue(LinkQueue *Q, QElemType *e)
{
  QueuePtr p;
  if (Q->front == Q->rear) // 队列为空
    return ERROR;
  p = Q->front->next;
  *e = p->data;
  Q->front->next = p->next; // 队头结点的后继指向原队头结点的后继
  if (Q->rear == p)         // 若队头是队尾，则删除后将 rear 指向头结点
    Q->rear = Q->front;
  free(p);
  return OK;
}