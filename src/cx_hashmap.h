#ifndef CUSTOM_EXTENDED_HASHMAP_H
#define CUSTOM_EXTENDED_HASHMAP_H

#define HASH_MAP_SIZE 255

typedef struct HashNode {
    char* key;
    char* value;
} HashNode;

typedef struct HashMap {
    HashNode* buckets[HASH_MAP_SIZE];
    int length;
} HashMap;

// 関数定義
HashMap* cx_create_hashmap();
void cx_put_hashmap(HashMap* hm, char* _key, char* _value);
int cx_get_hashmap(HashMap* hm, char* _key, char* _ovalue);
void cx_free_hashmap(HashMap* hm);

#endif // CUSTOM_EXTENDED_HASHMAP_H
