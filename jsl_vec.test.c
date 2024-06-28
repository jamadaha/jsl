#include "jsl_vec.h"
#include "jsl_test.h"
#include <stdbool.h>
#include <time.h>

void range(size_t max) {
    clock_t start = clock();

    bool valid = true;

    size_t *vec = vec_new(sizeof(size_t));
    for (size_t i = 0; i < max; i++) {
        vec_push(vec, i);
        if (vec_back(vec) != i) valid = false;
    }

    clock_t end   = clock();

    ASSERT("RANGE Values", valid);
    ASSERT("RANGE Size", vec_size(vec) == max);
    printf("[RANGE] %zu - %f\n", max, (float)(end - start) / CLOCKS_PER_SEC);
    vec_free(vec);
}

void reverse(size_t max) {
    clock_t start = clock();

    bool valid = true;

    size_t *vec = vec_new(sizeof(size_t));
    for (size_t i = 0; i < max; i++)
        vec_push(vec, i);

    vec_reverse(vec);
    for (size_t i = 0; i < max; i++)
        if (vec[i] != max - i - 1) valid = false;

    clock_t end   = clock();

    ASSERT("[REVERSE] Values", valid);
    ASSERT("[REVERSE] Size", vec_size(vec) == max);
    printf("REVERSE %zu - %f\n", max, (float)(end - start) / CLOCKS_PER_SEC);
    vec_free(vec);

}

int main(void) { 
    range(10000000);
    reverse(10000000);
}
