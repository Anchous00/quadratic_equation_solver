#include "quadratic.h"

int main( void )
{
    quadratic_equation equations[MAX_EQUATIONS_AMOUNT] = {};
    int equations_number = 0;

    equations_number = input_equations(equations);

    solve_equations(equations, equations_number);

    output_equations(equations, equations_number);

    // Case styles:
    // 1) camelCase
    // 2) snake_case
    // 3) PascalCase
    // 4) kebab-case

    return SUCCESSFUL_ENDING;
}



