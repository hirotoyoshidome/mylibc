#include "cx_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *cx_init_list() {
    List *l = (List *)malloc(sizeof(List));
    if (l == NULL) {
        return NULL;
    }

    return l;
}

void cx_push_list(List *l, char *_value) {
    if (l == NULL || _value == NULL) {
        return;
    }

    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (node == NULL) {
        return NULL;
    }

    char *val = (char *)malloc(sizeof(*_value));
    if (val == NULL) {
        return NULL;
    }

    strcpy(val, _value);
    node->value = val;

    // 初回のノード追加の場合はリストにノードを設定
    if (l->front == NULL) {
        l->front = node;
    } else {
        // 初回移行は最後のノードにポインタを設定する
        ListNode *t = l->front;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = node;
    }
}

// コールバックにはしない
void cx_foreach_show_list(List *l) {
    if (l == NULL) {
        return;
    }

    ListNode *node = l->front;
    while (node->next != NULL) {
        printf("%s\n", node->value);
        node = node->next;
    }
    printf("%s\n", node->value);
}

void cx_free_list(List *l) {
    if (l == NULL) {
        return;
    }

    // ノードの解放(先頭から解放する)
    while (l->front != NULL) {
        ListNode *node = l->front;
        // 先頭ノードをつなぎ替える
        l->front = node->next;

        free(node->value);
        node->value = NULL;
        free(node);
        node = NULL;
    }

    // リストの解放
    free(l);
    l = NULL;
}
