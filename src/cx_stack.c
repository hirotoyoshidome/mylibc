#include "cx_stack.h"
#include <stdbool.h>
#include <stddef.h>

// TODO boolやめる

void cx_init_stack(Stack *s) {
    if (s == NULL) {
        return;
    }

    // 空の場合は-1を設定
    s->top = -1;
}

// 空判定
bool cx_is_empty_stack(Stack *s) {
    if (s == NULL) {
        return false;
    }

    return s->top == -1;
}

// 満杯判定
bool cx_is_full_stack(Stack *s) {
    if (s == NULL) {
        return false;
    }

    return s->top == STACK_SIZE - 1;
}

// 追加
bool cx_push_stack(Stack *s, int value) {
    if (s == NULL) {
        return false;
    }

    if (cx_is_full_stack(s)) {
        return false;
    }
    s->top++;
    s->data[s->top] = value;

    return true;
}

// 取り出し
bool cx_pop_stack(Stack *s, int *value) {
    if (s == NULL || value == NULL) {
        return false;
    }

    if (cx_is_empty_stack(s)) {
        return false;
    }
    *value = s->data[s->top];
    s->top--;

    return true;
}
