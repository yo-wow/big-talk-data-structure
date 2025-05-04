#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int QElemType;
typedef struct
{
  QElemType data[MAXSIZE];
  int front; // 头指针
  int rear;  // 尾指针
} SqQueue;

// 初始化
Status InitQueue(SqQueue *Q)
{
  Q->front = 0;
  Q->rear = 0;
  return OK;
}

// 求元素个数
int QueueLength(SqQueue Q)
{
  return (Q.front - Q.rear + MAXSIZE) % MAXSIZE; // 通用计算队列长度的公式
}

// 入队
Status EnQueue(SqQueue *Q, QElemType e)
{
  if ((Q->rear + 1) % MAXSIZE == Q->front) // 队满
  {
    return ERROR;
  }
  Q->data[Q->rear] = e;              // 入队
  Q->rear = (Q->rear + 1) % MAXSIZE; // 队尾指针后移，如果尾指针已经到达了数组末尾，则重新指向数组首地址

  return OK;
}

// 出队
Status DeQueue(SqQueue *Q, QElemType *e)
{
  if (Q->front == Q->rear) // 队空
  {
    return ERROR;
  }
  *e = Q->data[Q->front];              // 队头元素出队
  Q->front = (Q->front + 1) % MAXSIZE; // 队头指针后移，如果头指针已经到达了数组末尾，则重新指向数组首地址

  return OK;
}