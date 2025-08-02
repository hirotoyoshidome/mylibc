#include "cx_list.h"
#include <assert.h>

void test_list_01() {
    List *l = cx_init_list();
    assert(l != NULL);

    cx_free_list(l);
    assert(l != NULL);

    l = NULL;
    assert(l == NULL);
}
