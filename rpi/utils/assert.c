#include "assert.h"

void assert(Boolean cond, char* err_msg) {
    if (cond) return;
    while (1);
}
