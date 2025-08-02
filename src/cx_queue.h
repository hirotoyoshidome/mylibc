#ifndef CUSTOM_EXTENDED_QUEUE_H
#define CUSTOM_EXTENDED_QUEUE_H

#include <stdbool.h>

#define QUEUE_SIZE 255

// キュー(FIFO)、要素数固定
typedef struct Queue {
    int data[QUEUE_SIZE];
    int front; // 先頭インデックス
    int rear;  // 末尾の次のインデックス
    int count; // 要素数
} Queue;

void cx_init_queue(Queue *q);
bool cx_is_empty_queue(Queue *q);
bool cx_is_full_queue(Queue *q);
bool cx_enqueue(Queue *q, int value);
bool cx_dequeue(Queue *q, int *value);

#endif // CUSTOM_EXTENDED_QUEUE_H
