#include <stdio.h>

#define MaxLength 30

typedef char ElementType;

typedef struct
{
    ElementType Elements[MaxLength];
    int Top_idx;
} Stack;

// tao ngan xep rong
void MakeNull_Stack(Stack *S)
{
    S->Top_idx = MaxLength;
}

// kiem tra ngan xep rong
int Empty_Stack(Stack S)
{
    return (S.Top_idx == MaxLength);
}

// kiem tra ngan xep day
int Full_Stack(Stack S)
{
    return (S.Top_idx == 0);
}

// lay noi dung phan tu tai vi tri dinh cua ngan xep
ElementType Top(Stack S)
{
    if (!Empty_Stack(S))
    {
        return S.Elements[S.Top_idx];
    }
    else
    {
        printf("NULL Stack");
        return NULL;
    }
}

// them phan tu vao ngan xep
void Push(ElementType X, Stack *S)
{
    if (Full_Stack(*S))
    {
        printf("Full Stack");
    }
    else
    {
        S->Top_idx = (S->Top_idx - 1);
        // giam top 1 don vi (cho TOP chi den phan tu ke)
        S->Elements[S->Top_idx] = X;
        // gia tri phan tu tai Top_idx bang X
    }
}

// xoa' phan tu ra khoi ngan xep
void Pop(Stack *S)
{
    if (Empty_Stack(*S))
    {
        printf("Stack is null");
    }
    else
    {
        S->Top_idx = S->Top_idx - 1;
    }
}
