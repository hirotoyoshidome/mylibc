#ifndef CUSTOM_EXTENDED_STRING_H
#define CUSTOM_EXTENDED_STRING_H

// free(sepd[0])必要
int cx_split(char *sepd[], char *txt, char *sep);
// free必要
char *cx_concat(char *txt1, char *txt2);
// free必要
char *cx_trim(char *txt);

// free必要
char *cx_upper(char *txt);
// free必要
char *cx_lower(char *txt);

int cx_startswith(char *txt, char *tar);
int cx_endswith(char *txt, char *tar);

#endif // CUSTOM_EXTENDED_STRING_H
