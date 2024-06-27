#include "jsl_vec.h"
#include "test.h"

int main(void) {
    int *vec = vec_alloc(3, sizeof(int));
    ASSERT("created", vec);
    ASSERT_EQ("size_0", vec_size(vec), 0);
    ASSERT_EQ("capacity_3", vec_capacity(vec), 3);
    vec_push(vec, 0);
    ASSERT_EQ("size_1", vec_size(vec), 1);
    ASSERT_EQ("capacity_3", vec_capacity(vec), 3);
    vec_push(vec, 1);
    ASSERT_EQ("size_2", vec_size(vec), 2);
    ASSERT_EQ("capacity_3", vec_capacity(vec), 3);
    vec_push(vec, 2);
    ASSERT_EQ("size_3", vec_size(vec), 3);
    ASSERT_EQ("capacity_3", vec_capacity(vec), 3);
    vec_push(vec, 3);
    ASSERT_EQ("size_4", vec_size(vec), 4);
    ASSERT_EQ("capacity_9", vec_capacity(vec), 9);
    ASSERT_EQ("pop_equals_3", vec_pop(vec), 3);
    ASSERT_EQ("size_3", vec_size(vec), 3);
    ASSERT_EQ("capacity_9", vec_capacity(vec), 9);
    vec_free(vec);
}
