#include "minunit.h"
#include "../includes/mandatory/push_swap.h"


MU_TEST (test_rotate) {

    int array[2];

	array[0] = 3;
	array[1] = 2;

    rotate(array, 2);

    mu_check(array[0] == 2 && array[1] == 3);
}

MU_TEST_SUITE (test_rotate_suite) {
	MU_RUN_TEST (test_rotate);
}

int main() {
	MU_RUN_SUITE(test_rotate_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
