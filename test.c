// #include "quadratic.c"
#include "utils.h"
#include "quadratic.h"

const int TEST_AMOUNT = 5;

int is_roots_equal(quadratic_equation equation1, quadratic_equation equation2);

int main( void )
{
    quadratic_equation control_equations[TEST_AMOUNT]  = {{{1, -5, 6}, {3, 2}, TWO_ROOTS}, {{0, 0, 1}, {0, 0}, NO_ROOTS}, {{0, 2, -4}, {2, 0}, ONE_ROOT}, {{1, 2, 1}, {-1, 0}, ONE_ROOT}, {{1, -9, 20}, {5, 4}, TWO_ROOTS}};
    quadratic_equation test_equations[TEST_AMOUNT]     = {{{1, -5, 6}, {0, 0}, NO_ROOTS},  {{0, 0, 1}, {0, 0}, NO_ROOTS}, {{0, 2, -4}, {0, 0}, NO_ROOTS}, {{1, 2, 1}, {0, 0}, NO_ROOTS},  {{1, -9, 20},{0, 0}, NO_ROOTS}};

    int successful_tests = 0;

    for(int i = 0; i < TEST_AMOUNT; i++)
    {
        solve_quadratic_equation(&test_equations[i]);
        //print_equation(test_equations[i]);
        if (is_roots_equal(test_equations[i], control_equations[i]))
        {
            successful_tests++;
        }
        else
        {
            printf("\x1b[31mGOVNO on %d iteration\n\x1b[0m", i + 1);
            printf("expected:\n");
            print_equation(control_equations[i]);
            printf("result:\n");
            print_equation(test_equations[i]);
        }
    }
    printf("\x1b[32mSuccessful %d tests of %d\x1b[0m\n", successful_tests, TEST_AMOUNT);
    return 0;
}

int is_roots_equal(quadratic_equation equation1, quadratic_equation equation2)
{
    return equation1.roots_number == equation2.roots_number &&
           is_zero(equation1.roots[0] - equation2.roots[0]) &&
           is_zero(equation1.roots[1] - equation2.roots[1]);
}
