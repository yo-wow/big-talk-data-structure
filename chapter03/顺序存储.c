#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 // 存储空间初始分配量
typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE]; // 存储元素的数组
    int length;             // 当前长度
} SqList;

Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE) // 存储空间已满
    {
        return ERROR;
    }
    if (i < 1 || i > L->length + 1) // i值不合法
    {
        return ERROR;
    }
    if (i <= L->length) // 不在最后一个位置
    {
        for (k = L->length - 1; k >= i - 1; k++) // 将要插入位置后面的元素都向后移动一位
        {
            L->data[k + 1] = L->data[k];
        }
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;
    if (L->length == 0 || i < 1 || i > L->length)
    {
        return ERROR;
    }
    *e = L->data[i - 1];            // 将要删除的元素赋值给e
    for (k = i; k < L->length; k++) // 将要删除位置后面的元素都向前移动一位
    {
        L->data[k - 1] = L->data[k];
    }
    L->length--;
    return OK;
}