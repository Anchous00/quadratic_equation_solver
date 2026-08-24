#include "quadratic.h"


//const int MAX_TEST_AMOUNT = 100;

bool is_roots_equal( quadratic_equation equation1, quadratic_equation equation2 );
int run_test( quadratic_equation *test_equations, quadratic_equation *control_equations, int equations_number);

int main( void )//TODO
{
    quadratic_equation control_equations[MAX_TEST_AMOUNT] = {};
    quadratic_equation test_equations[MAX_TEST_AMOUNT]    = {};

    int successful_tests = 0;
    FILE *control_file = fopen("control.txt", "r");
    FILE *test_file = fopen("test.txt", "r");

    assert(test_file);
    assert(control_file);

    int equations_number = read_equations_from_file( control_equations, control_file );
    printf("read %d test equations %d control equations\n", read_equations_from_file( test_equations, test_file ), equations_number);

    successful_tests = run_test(test_equations, control_equations, equations_number);

    printf(GREEN "Successful %d tests of %d\n" WHITE, successful_tests, equations_number);

    assert(fclose(test_file) != EOF);
    assert(fclose(control_file) != EOF);

    return SUCCESSFUL_ENDING;
}

bool is_roots_equal( quadratic_equation equation1, quadratic_equation equation2 )
{
    return equation1.roots_number == equation2.roots_number &&
            (   is_zero(equation1.roots[0] - equation2.roots[0]) || (isnan(equation1.roots[0]) && isnan(equation2.roots[0]))   ) &&
            (   is_zero(equation1.roots[1] - equation2.roots[1]) || (isnan(equation1.roots[1]) && isnan(equation2.roots[1]))   );
}

/*enum ROOTS_NUMBER roots_number( const char *roots_number)
{

}
*/

int run_test( quadratic_equation *test_equations, quadratic_equation *control_equations, int equations_number )
{
    int successful_tests = 0;
    for(int i = 0; i < equations_number; i++)
    {
        solve_quadratic_equation(&test_equations[i]);
        //print_equation(test_equations[i]);
        if (is_roots_equal(test_equations[i], control_equations[i]))
        {
            successful_tests++;
        }
        else
        {
            printf(RED "GOVNO on %d iteration\n" WHITE, i + 1);
            printf("expected:\n");
            print_equation(control_equations[i]);
            printf("result:\n");
            print_equation(test_equations[i]);
        }
    }

    return successful_tests;
}
