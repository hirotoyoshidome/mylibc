#include "cx_readcsv.h"

#include "cx_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cx_read_csv(CSV *csv, char *filepath) {
    if (csv == NULL || filepath == NULL) {
        return;
    }

    FILE *f = fopen(filepath, "r");
    if (f == NULL) {
        return;
    }

    int current = 0;
    while (current < CSV_MAX_ROWS) {
        char *s = (char *)malloc(sizeof(char[255]));
        if (s == NULL) {
            break;
        }

        if (fgets(s, CSV_MAX_COLS, f) == NULL) {
            break;
        }

        // 改行を削除(改行の場所にEOSを設定)
        s[strcspn(s, "\n")] = '\0';

        // 空文字ならスキップ
        if (strcmp(s, "") == 0) {
            continue;
        }

        // リストに詰める
        List *row = cx_init_list();
        // 残・分割してlistに詰める
        cx_push_list(row, s);

        csv->rows[current] = row;
        current++;
    }

    // 長さを保持
    csv->length = current;

    fclose(f);
}

void cx_free_csv(CSV *csv) {
    if (csv == NULL) {
        return;
    }

    for (int i = 0; i < csv->length; i++) {
        List *l = csv->rows[i];
        if (l != NULL) {
            cx_free_list(l);
        }
    }
}
