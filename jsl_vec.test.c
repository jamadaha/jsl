#include "jsl_vec.h"
#include "jsl_test.h"

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
    vec_reverse(vec);
    ASSERT_EQ("size_3", vec_size(vec), 3);
    ASSERT_EQ("capacity_9", vec_capacity(vec), 9);
    ASSERT_EQ("equals_0", vec[0], 2);
    ASSERT_EQ("equals_1", vec[1], 1);
    ASSERT_EQ("equals_2", vec[2], 0);
    vec_push(vec, 3);
    vec_reverse(vec);
    ASSERT_EQ("size", vec_size(vec), 4);
    ASSERT_EQ("capacity", vec_capacity(vec), 9);
    ASSERT_EQ("equals", vec[0], 3);
    ASSERT_EQ("equals", vec[1], 0);
    ASSERT_EQ("equals", vec[2], 1);
    ASSERT_EQ("equals", vec[3], 2);
    ASSERT_EQ("front", vec_front(vec), 3);
    ASSERT_EQ("back", vec_back(vec), 2);
    vec_pop(vec);
    ASSERT_EQ("back", vec_back(vec), 1);
    vec_shrink(vec);
    ASSERT_EQ("shrink correctly resizes", vec_capacity(vec), 3);
    vec_shuffle(vec);
    ASSERT("something changed", vec[0] != 3 || vec[1] != 0 || vec[2] != 1);
    vec_clear(vec);
    ASSERT_EQ("clear leaves capacity unchanged", vec_capacity(vec), 3);
    ASSERT_EQ("clear sets size to zero", vec_size(vec), 0);
    vec_free(vec);
}
