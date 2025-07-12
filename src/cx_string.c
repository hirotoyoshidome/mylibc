#include "cx_string.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


// 文字列分割 非破壊(呼び出し側でsepd[0]のメモリを解放する必要があります)
int cx_split(char* sepd[], char* txt, char* sep) {
    char* buf = malloc(strlen(txt) + 1);
    if (!buf) return -1;
    strcpy(buf, txt);

    int idx = 0;
    char* s = strtok(buf, sep);
    while(s) {
        sepd[idx] = s;
        idx++;
        s = strtok(NULL, sep);
    }
    // 配列の終端を設定
    sepd[idx] = NULL;

    return idx;
}

// 文字列結合(呼び出し側で解放する)
char* cx_concat(char* txt1, char* txt2) {
    // ヒープに領域を確保する
    size_t size = sizeof(char) * (strlen(txt1) + strlen(txt2) + 1);
    char* res = (char*)malloc(size);
    if (!res) {
        return NULL;
    }

    // コピー
    strcpy(res, txt1);
    strcpy(res, txt2);

    return res;
}

// trim(メモリの解放の必要あり)
char* cx_trim(char* txt) {
    if (!txt) return NULL;

    // 先頭の空白をスキップ(空白の間はポインタを進める)
    while(isspace((unsigned char)* txt)) {
        txt++;
    }

    // 空白のみの場合(EOSになっている場合)
    if(*txt == '\0') {
        // コピーして返却
        char* res = (char*)malloc(1);
        if (res) {
            *res = '\0';
        }
        return res;
    }

    // 末尾の空白を削除(EOSは除いて空白の場合はポインタをつめてゆく)
    char* end = txt + strlen(txt) - 1;
    while (end > txt && isspace((unsigned char)* end)) {
        end--;
    }

    // 新しい文字列を作成して返却(EOSを考慮)
    size_t length = (size_t)(end - txt + 1);
    char* res = (char*)malloc(length + 1);
    if (!res) return NULL;

    memcpy(res, txt, length);
    // EOSをセット
    res[length] = '\0';

    return res;
}

// 大文字に変換(free必要)
char* cx_upper(char* txt) {
    if (!txt) return NULL;

    size_t len = strlen(txt);
    char* res = (char*)malloc(len + 1);
    if (!res) return NULL;

    for (size_t i = 0; i < len; i++) {
        res[i] = toupper((unsigned char)txt[i]);
    }
    // EOSを設定
    res[len] = '\0';

    return res;
}

// 小文字に変換(free必要)
char* cx_lower(char* txt) {
    if (!txt) return NULL;

    size_t len = strlen(txt);
    char* res = (char*)malloc(len + 1);
    if (!res) return NULL;

    for (size_t i = 0; i < len; i++) {
        res[i] = tolower((unsigned char)txt[i]);
    }
    // EOSを設定
    res[len] = '\0';

    return res;
}

// 対象の文字で始まるか判定
int cx_startswith(char* txt, char* tar) {
    size_t len = strlen(tar);
    // 文字数を指定して比較
    return strncmp(txt, tar, len) == 0;
}

// 対象の文字で終わるか判定
int cx_endswith(char* txt, char* tar) {
    size_t txtlen = strlen(txt);
    size_t tarlen = strlen(tar);

    if (txtlen < tarlen) return 0;

    // 対象のところまでポインタを進めてから比較
    return strcmp(txt + txtlen - tarlen, tar) == 0;
}
