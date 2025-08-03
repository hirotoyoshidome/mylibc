#ifndef CUSTOM_EXTENDED_HASHMAP_H
#define CUSTOM_EXTENDED_HASHMAP_H

#define HASH_MAP_SIZE 255

typedef struct HashNode {
    char *key;
    char *value;
} HashNode;

typedef struct HashMap {
    HashNode *buckets[HASH_MAP_SIZE];
    int length;
} HashMap;

HashMap *cx_init_hashmap();
void cx_free_hashmap(HashMap *hm);

// 値の設定
void cx_put_hashmap(HashMap *hm, char *_key, char *_value);

// 値の取り出し
int cx_get_hashmap(HashMap *hm, char *_key, char *_ovalue);

#endif // CUSTOM_EXTENDED_HASHMAP_H
