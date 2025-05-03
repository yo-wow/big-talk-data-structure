#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;
typedef struct StackNode
{
  SElemType data;         // 存储当前结点的数据
  struct StackNode *next; // 指向下一个结点的指针
} StackNode,              // 链栈的结点，包含数据域 data 和指针域 next
    *LinkStackPtr;        // 指向 StackNode 的指针类型别名（等同于 StackNode*）

typedef struct LinkStack
{
  LinkStackPtr top; // 栈顶指针（指向最新入栈的结点）
  int count;        // 栈中元素个数
} LinkStack;

// 进栈
Status Push(LinkStack *S, SElemType e)
{
  LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
  p->data = e;
  p->next = S->top; // 把当前栈顶元素赋值给新结点的直接后继
  S->top = p;       // 将新的结点赋值给栈顶指针
  S->count++;
  return OK;
}

// 出栈
Status Pop(LinkStack *S, SElemType *e)
{
  LinkStackPtr p;
  if (StackEmpty(*S))
    return ERROR;
  *e = p->data;
  p = S->top;            // 将栈顶结点赋值给p
  S->top = S->top->next; // 使得栈顶指针下移一位，指向后一结点
  free(p);               // 释放结点p
  S->count--;
  return OK;
}