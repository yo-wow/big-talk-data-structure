#include <stdio.h>

#define MAX_LENGTH 255
typedef char String[MAX_LENGTH + 1]; // 下标为 0 的位置存储字符串长度

// 初始化字符串
void StrAssign(String S, const char *chars)
{
  int i = 0;
  while (chars[i] != '\0' && i < MAX_LENGTH)
  {
    S[i + 1] = chars[i];
    i++;
  }
  S[0] = i; // 存储字符串长度
}

// Index 函数，返回子串 T 在主串 S 中第 pos 个字符之后的位置，若未找到，则返回 0
// 主串 S 和子串 T 的长度分别存在 S[0] 和 T[0] 中
// T 非空，1 <= pos <= StrLength(S)
int Index(String S, String T, int pos)
{
  int i = pos;                   // i 用于主串 S 中当前位置下标，若 pos 不为 1 则从 pos 位置开始匹配
  int j = 1;                     // j 用于子串 T 中当前位置下标
  while (i <= S[0] && j <= T[0]) // 若 i 小于 S 的长度且 j 小于 T 的长度时循环
  {
    if (S[i] == T[j]) // 两字母相等则继续
    {
      ++i;
      ++j;
    }
    else
    {
      i = i - j + 2; // i 退回到上次匹配首位的下一位
      j = 1;         // j 退回到子串 T 的首位
    }
  }

  if (j > T[0]) // 若 j 大于 T 的长度，则匹配成功
    return i - T[0];
  else
    return 0; // 匹配失败，返回 0
}

int main()
{
  String S, T;
  StrAssign(S, "abcabcabd");
  StrAssign(T, "abcabd");

  int pos = 1;
  int result = Index(S, T, pos);

  if (result != 0)
  {
    printf("子串在主串中第 %d 个字符之后首次出现的位置是: %d\n", pos, result);
  }
  else
  {
    printf("未找到子串。\n");
  }

  return 0;
}