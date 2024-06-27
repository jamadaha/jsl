#include <stdio.h>

#define RED(s) "\033[31;1m" s "\033[0m"
#define GREEN(s) "\033[32;1m" s "\033[0m"

#define ASSERT(s, c)                                                                               \
    if (c)                                                                                         \
        printf("[  " GREEN("OK") "  ] %s\n", s);                                                   \
    else                                                                                           \
        printf("[ " RED("FAIL") " ] %s\n", s);

#define ASSERT_EQ(s, a, b) ASSERT(s, a == b)
#define ASSERT_GT(s, a, b) ASSERT(s, a > b)
#define ASSERT_LT(s, a, b) ASSERT(s, a < b)
