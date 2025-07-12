#include "cx_hashmap.h"
#include <stdlib.h>
#include <string.h>

// HashMapの作成
HashMap* cx_create_hashmap() {
    HashMap* hm = (HashMap*)malloc(sizeof(HashMap));
    if (!hm) return NULL;

    memset(hm->buckets, 0, sizeof(hm->buckets));
    hm->length = 0;
    return hm;
}

// 値の設定
void cx_put_hashmap(HashMap* hm, char* _key, char* _value) {
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    char* k = (char*)malloc(sizeof(*_key));
    char* v = (char*)malloc(sizeof(*_value));
    strcpy(k, _key);
    strcpy(v, _value);

    node->key = k;
    node->value = v;
    hm->buckets[hm->length] = node;
    hm->length++;
}

// 値の取り出し
int cx_get_hashmap(HashMap* hm, char* _key, char* _ovalue) {
    HashNode** nodes = hm->buckets;
    for (int i = 0; i < hm->length; i++) {
        HashNode* node = nodes[i];
        if (strcmp(node->key, _key) == 0) {
            strcpy(_ovalue, node->value);
            return 1;
        }
    }
    return 0;
}

// メモリの開放
void cx_free_hashmap(HashMap* hm) {
    HashNode** nodes = hm->buckets;
    for (int i = 0; i < hm->length; i++) {
        HashNode* node = nodes[i];
        // ノードの開放
        free(node->key);
        free(node->value);
        free(node);
    }
    // ハッシュマップの開放
    free(hm);
}
