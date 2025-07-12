#ifndef CUSTOM_EXTENDED_LIST_H
#define CUSTOM_EXTENDED_LIST_H


// 連結リスト(文字列のみ)
typedef struct ListNode {
    char* value;
    // 次のノードのポインタを保持
    struct ListNode* next;
} ListNode;

typedef struct List {
    // 先頭ノードのポインタのみ保持
    ListNode* front;
} List;

List* cx_create_list();
void cx_push_list(List* l, char* _value);
void cx_foreach_show_list(List* l);
void cx_free_list(List* l);

#endif // CUSTOM_EXTENDED_LIST_H
