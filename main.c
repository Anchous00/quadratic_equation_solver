
#include "quadratic.h"

int main( void )
{
    quadratic_equation equation = {NAN, NAN, NAN, 1, 1, INF_ROOTS};

    printf("\x1b[0;0m");

    if(!input_coefficients(&equation))
    {
        return 1;
    }
    
    solve_quadratic_equation(&equation);
    print_answers(&equation);
    // Case styles:
    // 1) camelCase
    // 2) snake_case
    // 3) PascalCase
    // 4) kebab-case

    return 0;
}

