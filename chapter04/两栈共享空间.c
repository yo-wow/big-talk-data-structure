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
  int top1; // 栈1栈顶指针
  int top2; // 栈2栈顶指针
} SqDoubleStack;

// 进栈
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
  if (S->top1 + 1 == S->top2) // 栈满
  {
    return ERROR;
  }
  if (stackNumber == 1) // 栈1 进栈
  {
    S->data[++S->top1] = e; // top1+1 后给数组元素赋值
  }
  else // 栈2 进栈
  {
    S->data[--S->top2] = e; // top2-1 后给数组元素赋值
  }
}

// 出栈
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
  if (stackNumber == 1) // 栈1 出栈
  {
    if (S->top1 == -1) // 栈空
    {
      return ERROR;
    }
    *e = S->data[S->top1--]; // 取数组元素后top1-1
  }
  else // 栈2 出栈
  {
    if (S->top2 == MAXSIZE) // 栈空
    {
      return ERROR;
    }
    *e = S->data[S->top2++]; // 取数组元素后top2+1
  }
}