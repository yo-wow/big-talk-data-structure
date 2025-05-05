#include <stdio.h>

#define MAX_LENGTH 255
typedef char String[MAX_LENGTH + 1]; // 下标为 0 的位置存储字符串长度

// 计算返回子串的 next 数组
void get_next(String T, int *next)
{
  int i, j;
  i = 1;
  j = 0;
  next[1] = 0;
  while (i < T[0]) // 此处 T[0] 标识串 T 的长度
  {
    if (j == 0 || T[i] == T[j]) // T[i] 表示后缀的单个字符，T[j] 表示前缀的单个字符
    {
      i++;
      j++;
      next[i] = j;
    }
    else
    {
      j = next[j]; // 若字符不相同，则 j 值回溯
    }
  }
}

// 返回子串 T 在主串 S 中第 pos 个字符之后的位置，不存在则返回 0
int index(String S, String T, int pos)
{
  int i = pos; // i 用于主串 S 当前位置下标值
  int j = 1;   // j 用于子串 T 当前位置下标值
  int next[MAX_LENGTH + 1];
  get_next(T, next);
  while (i <= S[0] && j <= T[0])
  {
    if (j == 0 || S[i] == T[j]) // 两字母相等则继续，相对于朴素算法增加了 j=0 判断
    {
      i++;
      j++;
    }
    else
    {
      j = next[j]; // j 退回到合适的位置，i 值不变
    }
  }

  if (j > T[0])
  {
    return i - T[0];
  }
  else
  {
    return 0;
  }
}

// 求模式串 T 的 next 函数修正值并存入数组 nextval
void get_nextval(String T, int *nextval)
{
  int i, j;
  i = 1;
  j = 0;
  nextval[1] = 0;
  while (i < T[0])
  {
    if (j == 0 || T[i] == T[j])
    {
      i++;
      j++;
      if (T[i] != T[j])          // 若当前字符与前缀字符不同
        nextval[i] = j;          // 则当前的 j 为 nextval 在 i 位置的值
      else                       // 若当前字符与前缀字符相同
        nextval[i] = nextval[j]; // 则将前缀字符的 nextval 值赋给nextval 在 i 位置的值
    }
    else
    {
      j = nextval[j]; // 若字符不相同，则 j 值回溯
    }
  }
}