#include "cx_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Listの生成
List* cx_create_list() {
    List* l = (List*)malloc(sizeof(List));
    if (!l) return NULL;

    return l;
}

// Listに追加
void cx_push_list(List* l, char* _value) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    char* val = (char*)malloc(sizeof(*_value));
    strcpy(val, _value);
    node->value = val;

    // 初回のノード追加の場合はリストにノードを設定
    if (l->front == NULL) {
        l->front = node;
    } else {
        // 初回移行は最後のノードにポインタを設定する
        ListNode* t = l->front;
        while(t->next != NULL) {
            t = t->next;
        }
        t->next = node;
    }
}

// ループして表示(コールバックにはしない)
void cx_foreach_show_list(List* l) {
    ListNode* node = l->front;
    while(node->next != NULL) {
        printf("%s\n", node->value);
        node = node->next;
    }
    printf("%s\n", node->value);
}

// メモリの開放
void cx_free_list(List* l) {
    // ノードの解放(先頭から解放する)
    while(l->front != NULL) {
        ListNode* node = l->front;
        // 先頭ノードをつなぎ替える
        l->front = node->next;
        free(node->value);
        free(node);
    }
    // リストの解放
    free(l);
}
