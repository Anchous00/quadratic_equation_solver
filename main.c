/*!
* \file
* \brief файл с кодом запуска основной программы
*/

#include "quadratic.h"

int main( void )
{
    quadratic_equation equations[MAX_EQUATIONS_AMOUNT] = {};

    int equations_number = input_equations(equations);

    solve_equations(equations, equations_number);

    output_equations(equations, equations_number);

    return SUCCESSFUL_ENDING;
}



