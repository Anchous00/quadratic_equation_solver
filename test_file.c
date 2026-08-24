#include "quadratic.h"

void generate_random_equations( int equations_number );

const int MAX_COEFFICIENT = 1000;

int main( void )
{
    quadratic_equation test_equations[MAX_TEST_AMOUNT];

    generate_random_equations(100);

    FILE *input_address = fopen("random_equations.txt", "r");

    if (input_address == NULL)
    {
        printf("cant open file\n");
        return ERROR_OCCURRED_DURING_READING_FILE;
    }

    int equations_number = read_coefficients_from_file(test_equations, input_address);
    printf("successful read %d equations\n", equations_number);

    fclose(input_address);

    for(int i = 0; i < equations_number; i++)
    {
        solve_quadratic_equation(&test_equations[i]);
        printf("\nEquation %d: ", i + 1);
        print_equation(test_equations[i]);
    }

    return SUCCESSFUL_ENDING;
}

void generate_random_equations( int equations_number )
{
    int a = 0, b = 0, c = 0;

    FILE *file = fopen("random_equations.txt", "w");

    for(int i = 0; i < equations_number; i++)
    {
        a = rand() % MAX_COEFFICIENT;
        b = rand() % MAX_COEFFICIENT;
        c = rand() % MAX_COEFFICIENT;

        fprintf(file, "%d %d %d \n", a, b, c);
    }

    fclose(file);
}
