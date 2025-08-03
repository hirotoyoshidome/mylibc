#ifndef CUSTOM_EXTENDED_STACK_H
#define CUSTOM_EXTENDED_STACK_H

#define STACK_SIZE 255

// スタック(LIFO)、要素数固定
typedef struct Stack {
    int data[STACK_SIZE];
    int top; // 先頭インデックス
} Stack;

void cx_init_stack(Stack *s);

// 空判定
int cx_is_empty_stack(Stack *s);

// 満杯判定
int cx_is_full_stack(Stack *s);

// 追加
int cx_push_stack(Stack *s, int value);

// 取り出し
int cx_pop_stack(Stack *s, int *value);

#endif // CUSTOM_EXTENDED_STACK_H
