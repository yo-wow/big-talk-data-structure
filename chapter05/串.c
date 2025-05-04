#include <stdio.h>
#include <string.h>

// 定义字符串的最大长度
#define MAX_LENGTH 100

// 定义字符串结构体
typedef struct
{
  char ch[MAX_LENGTH + 1]; // 给字符串的结束符 '\0' 预留空间
  int length;
} String;

// 初始化字符串
// 参数 S：指向 String 结构体的指针，用于存储初始化后的字符串
// 参数 str：指向 C 风格字符串的指针，用于提供初始化的字符串内容
void InitString(String *S, const char *str)
{
  // 将传入的 C 风格字符串复制到 String 结构体的字符数组中
  strcpy(S->ch, str);
  // 计算传入字符串的长度，并赋值给 String 结构体的 length 成员
  S->length = strlen(str);
}

// 求字符串长度
// 参数 S：一个 String 结构体，代表要计算长度的字符串
// 返回值：字符串的长度
int StrLength(String S)
{
  return S.length;
}

// 取子串
// 参数 sub：指向 String 结构体的指针，用于存储取出的子串
// 参数 S：一个 String 结构体，代表主串
// 参数 pos：子串在主串中的起始位置（从 1 开始计数）
// 参数 len：子串的长度
void SubString(String *sub, String S, int pos, int len)
{
  // 检查起始位置和长度是否合法
  if (pos < 1 || pos > S.length || len < 0 || pos + len - 1 > S.length)
  {
    // 若不合法，将子串长度置为 0，并将字符数组置为空字符串
    sub->length = 0;
    sub->ch[0] = '\0';
    return;
  }
  // 从主串中复制指定长度的子串到子串结构体的字符数组中
  for (int i = 0; i < len; i++)
  {
    sub->ch[i] = S.ch[pos - 1 + i];
  }
  // 在子串字符数组末尾添加字符串结束符
  sub->ch[len] = '\0';
  // 设置子串的长度
  sub->length = len;
}

// 字符串比较
// 参数 S：一个 String 结构体，代表要比较的第一个字符串
// 参数 T：一个 String 结构体，代表要比较的第二个字符串
// 返回值：若两个字符串相等，返回 0；若 S 小于 T，返回负数；若 S 大于 T，返回正数
int StrCompare(String S, String T)
{
  return strcmp(S.ch, T.ch);
}

// Index 函数，用于在主串中查找子串的位置
// 参数 S：一个 String 结构体，代表主串
// 参数 T：一个 String 结构体，代表子串
// 参数 pos：查找的起始位置（从 1 开始计数）
// 返回值：若找到子串，返回子串在主串中的起始位置；若未找到，返回 0
int Index(String S, String T, int pos)
{
  int n, m, i;
  String sub;
  // 检查起始位置是否合法
  if (pos > 0)
  {
    // 获取主串的长度
    n = StrLength(S);
    // 获取子串的长度
    m = StrLength(T);
    // 初始化查找的起始位置
    i = pos;

    // 从起始位置开始，遍历主串，直到剩余长度不足以包含子串
    while (i <= n - m + 1)
    {
      // 从主串的第 i 个位置开始，取长度为 m 的子串
      SubString(&sub, S, i, m);

      // 比较取出的子串和目标子串是否相等
      if (StrCompare(sub, T) != 0)
        // 若不相等，将查找位置向后移动一位
        ++i;
      else
        // 若相等，返回子串在主串中的起始位置
        return i;
    }
  }

  // 若未找到子串，返回 0
  return 0;
}

int main()
{
  String S, T;
  // 初始化主串
  InitString(&S, "abcdefg");
  // 初始化子串
  InitString(&T, "cde");
  // 设置查找的起始位置
  int pos = 1;
  // 调用 Index 函数查找子串在主串中的位置
  int result = Index(S, T, pos);
  if (result != 0)
  {
    printf("子串在主串中的位置是: %d\n", result);
  }
  else
  {
    printf("未找到子串\n");
  }
  return 0;
}