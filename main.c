#include "quadratic.c"

int main( void )
{
    quadratic_equation equation;

    input_coefficients(&equation);
    quadratic_solver(&equation);
    print_answers(&equation);

    //dont_close_console();

    return 0;
}

