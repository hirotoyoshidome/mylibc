#include "cx_queue.h"
#include <stddef.h>

void cx_init_queue(Queue *q) {
    if (q == NULL) {
        return;
    }

    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

// 空判定
int cx_is_empty_queue(Queue *q) {
    if (q == NULL) {
        return -1;
    }

    return q->count == 0 ? 0 : 1;
}

// 満杯判定
int cx_is_full_queue(Queue *q) {
    if (q == NULL) {
        return -1;
    }

    return q->count == QUEUE_SIZE ? 0 : 1;
}

// エンキュー(追加)
int cx_enqueue(Queue *q, int value) {
    if (q == NULL) {
        return -1;
    }

    if (cx_is_full_queue(q)) {
        return 1;
    }
    // 一番後ろに追加
    q->data[q->rear] = value;
    // リングバッファ処理(循環するように)
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->count++;

    return 0;
}

// デュー(取り出し)
int cx_dequeue(Queue *q, int *value) {
    if (q == NULL || value == NULL) {
        return -1;
    }

    if (cx_is_empty_queue(q)) {
        return 1;
    }
    // 先頭を取り出し
    *value = q->data[q->front];
    // リングバッファ処理(循環するように)
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;

    return 0;
}
