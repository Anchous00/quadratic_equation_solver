/*!
* \file
* \brief файл с кодом запуска теста
*/

#include "quadratic.h"


bool is_roots_equal( quadratic_equation equation1, quadratic_equation equation2 );
int run_test( quadratic_equation *test_equations, quadratic_equation *control_equations, int equations_number, bool log);

int main( int argc, char *argv[] )
{
    char arg = '\0';
    bool test_log = false;

    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while ((arg = *++argv[0]))
        {
            switch (arg)
            {
                case 'z':
                    printf("ZZZZZZZZZ\n");
                    break;
                case 'l':
                    test_log = true;
                    break;
                default:
                    printf("undefined flag\n");
                    break;
            }
        }
    }

    quadratic_equation control_equations[MAX_TEST_AMOUNT] = {};
    quadratic_equation test_equations[MAX_TEST_AMOUNT]    = {};

    FILE *control_file = fopen("control.txt", "r");
    FILE *test_file = fopen("test.txt", "r");

    assert(test_file);
    assert(control_file);

    int equations_number = read_equations_from_file( control_equations, control_file );
    printf("read %d test equations %d control equations\n", read_equations_from_file( test_equations, test_file ), equations_number);

    int successful_tests = run_test(test_equations, control_equations, equations_number, test_log);

    printf(GREEN "Successful %d tests of %d\n" WHITE, successful_tests, equations_number);

    assert(fclose(test_file) != EOF);
    assert(fclose(control_file) != EOF);

    return SUCCESSFUL_ENDING;
}

int run_test( quadratic_equation *test_equations, quadratic_equation *control_equations, int equations_number, bool log )
{
    int successful_tests = 0;
    for(int i = 0; i < equations_number; i++)
    {
        solve_quadratic_equation(&test_equations[i]);
        //print_equation(test_equations[i]);
        if (is_roots_equal(test_equations[i], control_equations[i]))
        {
            successful_tests++;
            if (log)
            {
                printf("successful test %d:\n", successful_tests);
                fprint_answer(stdout, test_equations[i]);
            }
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

bool is_roots_equal( quadratic_equation equation1, quadratic_equation equation2 )
{
    double x11 = min(equation1.roots[0], equation1.roots[1]), x12 = min(equation2.roots[0], equation2.roots[1]);
    double x21 = max(equation1.roots[0], equation1.roots[1]), x22 = max(equation2.roots[0], equation2.roots[1]);

    return equation1.roots_number == equation2.roots_number &&
         (is_zero(x11 - x12) || (isnan(x11) && isnan(x12))) &&
         (is_zero(x21 - x22) || (isnan(x21) && isnan(x22)));
}
