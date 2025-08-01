#include <stdio.h>

#include "test_list.c"

typedef void (*TestFunc)(void);
typedef struct {
    const char *name;
    TestFunc func;
} TestCase;

int main() {

    TestCase tests[] = {{"test_list_01", test_list_01}};

    int test_num = sizeof(tests) / sizeof(TestCase);

    for (int i = 0; i < test_num; i++) {
        printf("Run: %s\n", tests[i].name);
        tests[i].func();
        printf("OK: %s\n", tests[i].name);
    }

    printf("#########################\n");
    printf("ALL TEST DONE. (%d CASES)\n", test_num);
    printf("#########################\n");

    return 0;
}
