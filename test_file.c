#include "quadratic.h"

void generate_random_equations( int equations_number );

const int MAX_COEFFICIENT = 10;

int main( void )
{
    quadratic_equation test_equations[MAX_TEST_AMOUNT];

    generate_random_equations(1000);

    FILE *input_address = fopen("random_equations.txt", "r");

    if (input_address == NULL)
    {
        printf("cant open file\n");
        return ERROR_OCCURRED_DURING_READING_FILE;
    }

    int equations_number = read_equations_from_file(test_equations, input_address);
    printf("successful read %d equations\n", equations_number);

    fclose(input_address);

    FILE *output_file = fopen("solved_equations.txt", "w");

    if (output_file == NULL)
    {
        printf("ERROR: cant open file");
        return MYERROR;
    }

    solve_equations(test_equations, equations_number);
    save_solved_equations(test_equations, equations_number, output_file);

    return SUCCESSFUL_ENDING;
}

void generate_random_equations( int equations_number )
{
    int a = 0, b = 0, c = 0;

    FILE *file = fopen("random_equations.txt", "w");

    for(int i = 0; i < equations_number; i++)
    {
        a = rand() % MAX_COEFFICIENT * (-1 + 2 * (rand() % 2));
        b = rand() % MAX_COEFFICIENT * (-1 + 2 * (rand() % 2));
        c = rand() % MAX_COEFFICIENT * (-1 + 2 * (rand() % 2));

        fprintf(file, "{%4d, %4d, %4d}  {NAN, NAN, NO_ROOTS } \n", a, b, c);
    }

    fclose(file);
}
