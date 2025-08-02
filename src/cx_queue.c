#include "cx_queue.h"
#include <stdbool.h>
#include <stddef.h>

// TODO boolやめる

void cx_init_queue(Queue *q) {
    if (q == NULL) {
        return;
    }

    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

// 空判定
bool cx_is_empty_queue(Queue *q) {
    if (q == NULL) {
        return false;
    }

    return q->count == 0;
}

// 満杯判定
bool cx_is_full_queue(Queue *q) {
    if (q == NULL) {
        return false;
    }

    return q->count == QUEUE_SIZE;
}

// エンキュー(追加)
bool cx_enqueue(Queue *q, int value) {
    if (q == NULL) {
        return false;
    }

    if (cx_is_full_queue(q)) {
        return false;
    }
    // 一番後ろに追加
    q->data[q->rear] = value;
    // リングバッファ処理(循環するように)
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->count++;

    return true;
}

// デュー(取り出し)
bool cx_dequeue(Queue *q, int *value) {
    if (q == NULL || value == NULL) {
        return false;
    }

    if (cx_is_empty_queue(q)) {
        return false;
    }
    // 先頭を取り出し
    *value = q->data[q->front];
    // リングバッファ処理(循環するように)
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;

    return true;
}
