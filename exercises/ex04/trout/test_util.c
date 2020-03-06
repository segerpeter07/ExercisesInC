#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "minunit.h"

static char *test1() {
    char* res = icmpcode_v4(0);
    // printf("%s",res);
    char *message = "test failed icmpcode_v4(0) should return \"network unreachable\" ";
    mu_assert(message, !strcmp(res, "network unreachable"));
    return NULL;
}

int main() {
    char *testResult = test1();
    if (testResult != NULL) {
        printf("%s\n", testResult);
    } else {
        printf("ALL TESTS PASSED\n");
    }

    return testResult != 0;
}