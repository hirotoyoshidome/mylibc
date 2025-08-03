#include "cx_stack.h"
#include <stddef.h>

void cx_init_stack(Stack *s) {
    if (s == NULL) {
        return;
    }

    // 空の場合は-1を設定
    s->top = -1;
}

int cx_is_empty_stack(Stack *s) {
    if (s == NULL) {
        return -1;
    }

    return s->top == -1 ? 0 : 1;
}

int cx_is_full_stack(Stack *s) {
    if (s == NULL) {
        return -1;
    }

    return s->top == STACK_SIZE - 1 ? 0 : 1;
}

int cx_push_stack(Stack *s, int value) {
    if (s == NULL) {
        return -1;
    }

    if (cx_is_full_stack(s)) {
        return 1;
    }
    s->top++;
    s->data[s->top] = value;

    return 0;
}

int cx_pop_stack(Stack *s, int *value) {
    if (s == NULL || value == NULL) {
        return -1;
    }

    if (cx_is_empty_stack(s)) {
        return 1;
    }
    *value = s->data[s->top];
    s->top--;

    return 0;
}
