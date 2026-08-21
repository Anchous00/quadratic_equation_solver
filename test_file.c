#include "quadratic.h"

int main( void )
{
    quadratic_equation test_equations[MAX_TEST_AMOUNT];
    FILE *input_address = fopen("test_equations.txt", "r");

    if (input_address == NULL)
        return ERROR_OCCURED_DURING_READING_FILE;

    int equations_number = input_coefficients_from_file(test_equations, input_address);
    printf("successful reading\n");
    fclose(input_address);

    for(int i = 0; i < equations_number; i++)
        {
        solve_quadratic_equation(&test_equations[i]);
        printf("\nEquation %d: ", i + 1);
        print_equation(test_equations[i]);
        }

    return SUCCESSFUL_ENDING;
}
