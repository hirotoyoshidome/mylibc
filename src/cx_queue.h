#ifndef CUSTOM_EXTENDED_QUEUE_H
#define CUSTOM_EXTENDED_QUEUE_H

#define QUEUE_SIZE 255

// キュー(FIFO)、要素数固定
typedef struct Queue {
    int data[QUEUE_SIZE];
    int front; // 先頭インデックス
    int rear;  // 末尾の次のインデックス
    int count; // 要素数
} Queue;

void cx_init_queue(Queue *q);

// 空判定
int cx_is_empty_queue(Queue *q);

// 満杯判定
int cx_is_full_queue(Queue *q);

// エンキュー(追加)
int cx_enqueue(Queue *q, int value);

// デュー(取り出し)
int cx_dequeue(Queue *q, int *value);

#endif // CUSTOM_EXTENDED_QUEUE_H
