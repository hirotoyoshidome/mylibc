#ifndef CUSTOM_EXTENDED_STRING_H
#define CUSTOM_EXTENDED_STRING_H

// 文字列分割 非破壊(free(sepd[0])必要)
int cx_split(char *sepd[], char *txt, char *sep);

// 文字列結合(free必要)
char *cx_concat(char *txt1, char *txt2);

// trim(free必要)
char *cx_trim(char *txt);

// 大文字に変換(free必要)
char *cx_upper(char *txt);

// 小文字に変換(free必要)
char *cx_lower(char *txt);

// 対象の文字で始まるか判定
int cx_startswith(char *txt, char *tar);

// 対象の文字で終わるか判定
int cx_endswith(char *txt, char *tar);

#endif // CUSTOM_EXTENDED_STRING_H
