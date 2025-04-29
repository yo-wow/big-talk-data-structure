#include <stdio.h>
#include <stdlib.h> // 添加此行以声明 free 和 malloc 函数
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000
typedef int Status;
typedef int ElemType;

// 线性表的单链表结点定义
typedef struct
{
  ElemType data;
  int cur; // 游标 cursor，为 0 时表示无指向
} Component, StaticLinkList[MAX_SIZE];

// 初始化
Status InitList(StaticLinkList space)
{
  for (int i = 0; i < MAX_SIZE - 1; i++)
  {
    space[i].cur = i + 1;
  }
  space[MAX_SIZE - 1].cur = 0; // 目前静态链表为空，最后一个元素的cur为0
  return OK;
}

// 申请一个结点
int Malloc_SLL(StaticLinkList space)
{
  int i = space[0].cur;
  if (space[0].cur)
  {
    space[0].cur = space[i].cur;
  }
  return i;
}

// 插入
Status ListInsert(StaticLinkList space, int i, ElemType e)
{
  int j, k, l;
  k = MAX_SIZE - 1; // k首先是最后一个元素的下标
  if (i < 1 || i > ListLength(space) + 1)
  {
    return ERROR;
  }
  j = Malloc_SLL(space);
  if (j)
  {
    space[j].data = e;
    for (l = 1; l <= i - 1; l++)
    {
      k = space[k].cur;
    }
    space[j].cur = space[k].cur; // 把第i个元素之前的cur赋值给新元素的cur
    space[k].cur = j;            // 把新元素的下标赋值给第i个元素的cur
    return OK;
  }
  return ERROR;
}

int ListLength(StaticLinkList space)
{
  int i = 0;
  int j = space[MAX_SIZE - 1].cur;
  while (j)
  {
    i++;
    j = space[j].cur;
  }
  return i;
}

// 删除
Status ListDelete(StaticLinkList space, int i, ElemType *e)
{
  if (i < 1 || i > ListLength(space))
  {
    return ERROR;
  }
  int j, k;
  k = MAX_SIZE - 1; // k首先是最后一个元素的下标
  for (j = 1; j <= i - 1; j++)
  {
    k = space[k].cur;
  }
  *e = space[k].data;
  j = space[k].cur;
  space[k].cur = space[j].cur;
  Free_SLL(space, j);
  return OK;
}

// 释放节点
void Free_SLL(StaticLinkList space, int i)
{
  space[i].cur = space[0].cur;
  space[0].cur = i;
}

// 静态列表的优缺点
// 优点：插入和删除只需要修改游标，不需要移动元素
// 缺点：1. 没有解决连续存储分配带来的表长难以确定的问题；2. 失去了顺序存储结构的随机存储特性