#include "cx_hashmap.h"
#include <stdlib.h>
#include <string.h>

// TODO エラー時処理

HashMap *cx_init_hashmap() {
    HashMap *hm = (HashMap *)malloc(sizeof(HashMap));
    if (hm == NULL) {
        return NULL;
    }

    memset(hm->buckets, 0, sizeof(hm->buckets));
    hm->length = 0;

    return hm;
}

void cx_put_hashmap(HashMap *hm, char *_key, char *_value) {
    if (hm == NULL || _key == NULL || _value == NULL) {
        return;
    }

    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    if (node == NULL) {
        return;
    }

    char *k = (char *)malloc(sizeof(*_key));
    char *v = (char *)malloc(sizeof(*_value));
    if (k == NULL || v == NULL) {
        return;
    }

    strcpy(k, _key);
    strcpy(v, _value);

    node->key = k;
    node->value = v;

    hm->buckets[hm->length] = node;
    hm->length++;
}

int cx_get_hashmap(HashMap *hm, char *_key, char *_ovalue) {
    if (hm == NULL || _key == NULL || _ovalue == NULL) {
        return -1;
    }

    HashNode **nodes = hm->buckets;
    for (int i = 0; i < hm->length; i++) {
        HashNode *node = nodes[i];
        if (strcmp(node->key, _key) == 0) {
            strcpy(_ovalue, node->value);
            return 1;
        }
    }

    return 0;
}

void cx_free_hashmap(HashMap *hm) {
    if (hm == NULL) {
        return;
    }

    HashNode **nodes = hm->buckets;
    for (int i = 0; i < hm->length; i++) {
        HashNode *node = nodes[i];
        // ノードの開放
        free(node->key);
        free(node->value);
        node->key = NULL;
        node->value = NULL;

        free(node);
        node = NULL;
    }

    // ハッシュマップの開放
    free(hm);
    hm = NULL;
}
