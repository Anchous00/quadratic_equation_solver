#include "quadratic.h"

int main( void )
{
    quadratic_equation equation = {NAN, NAN, NAN, 1, 1, INF_ROOTS};
    char choice = ' ';

    printf("Enter f for reading from file, c for reading from console, any key for exit\n");
    choice = (char)getchar();

    switch (choice)
    {
    case 'f':
        input_from_file();
        break;

    case 'c':
        if(!input_coefficients(&equation))
            return ERROR_DURING_READING_COEFFICIENTS;
        solve_quadratic_equation(&equation);
        print_answers(&equation);
        break;

    default:
        return ESCAPE;
        break;

    }

    // Case styles:
    // 1) camelCase
    // 2) snake_case
    // 3) PascalCase
    // 4) kebab-case

    return SUCCESSFUL_ENDING;
}

