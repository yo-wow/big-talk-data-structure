#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int SElemType;
typedef struct
{
  SElemType data[MAXSIZE];
  int top; // 栈顶指针
} SqStack;

// 进栈
Status Push(SqStack *S, SElemType e)
{
  if (S->top == MAXSIZE - 1) // 栈满
  {
    return ERROR;
  }
  S->top++;            // 栈顶指针加1
  S->data[S->top] = e; //  将e赋给栈顶元素
  return OK;
}

// 出栈
Status Pop(SqStack *S, SElemType *e)
{
  if (S->top == -1) // 栈空
  {
    return ERROR;
  }
  *e = S->data[S->top]; // 将栈顶元素赋给e
  S->top--;             // 栈顶指针减1
  return OK;
}