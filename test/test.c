#include "../src/calculator.h"
#include <check.h>


START_TEST(test_calculate)
{
    char *input[3] ={"(3^2)+5+3", "(5*10-40)+5", "(50*2*5 / 10)/2"};
    double exp[3] = {17, 15, 25};
        for (int i = 0; i < 3; ++i){
            char * input_expression = input[i];
            int my_int_array[20];
            char * my_char_array = malloc(30 * sizeof (char));
            array_digit(input_expression, my_int_array);
            int size_dare = arr_dare(input_expression, my_char_array);
            double inp = calculate(my_int_array, my_char_array, size_dare);

            ck_assert_double_eq_tol(inp, exp[i], 0.001);
            free(my_char_array);
        }

}
END_TEST

int main(void)
{
	Suite *s = suite_create("Module-control");
	TCase *tc_core = tcase_create("Module-control");

	tcase_add_test(tc_core, test_calculate);


	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}