#ifndef CUSTOM_EXTENDED_READCSV_H
#define CUSTOM_EXTENDED_READCSV_H

#include "cx_list.h"

// 1行あたりの最大文字数
#define CSV_MAX_COLS 255
// 最大行数
#define CSV_MAX_ROWS 255

// CSVの構造体(Listのポインタの配列を持つ)
typedef struct CSV {
    List *rows[CSV_MAX_ROWS];
    int length;
} CSV;

void cx_read_csv(CSV *csv, char *filepath);
void cx_free_csv(CSV *csv);

#endif // CUSTOM_EXTENDED_READCSV_H
