#include <assert.h>
#include "cx_list.h"

void test_list_01 () {
    List *l = cx_create_list();
    assert(l != NULL);

    cx_free_list(l);
    assert(l != NULL);

    l = NULL;
    assert(l == NULL);
}
