.test_vec:
	gcc -g -Wall -Wextra -O0 -fsanitize=address jsl_vec.test.c -o jsl_vec.test
	./jsl_vec.test
	rm ./jsl_vec.test

test: .test_vec
