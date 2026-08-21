#include <stdio.h>
#include <math.h>

enum ROOTS_NUMBER {
        NO_ROOTS  = 0,
        ONE_ROOT  = 1,
        TWO_ROOTS = 2,
        INF_ROOTS};

enum RETURN_VALUES{
        ERROR = 0,
        SUCCESS = 1};

const double EPSILON = 1e-16;
const int COEFFICIENTS_AMOUNT = 1;

struct quadratic_equation{
    double coefficients[3];
    double roots[2];
    enum ROOTS_NUMBER roots_number;
};

int solve_quadratic_equation( quadratic_equation *equation );
int solve_linear( quadratic_equation *equation );
int input_coefficients( quadratic_equation *equation );
void print_answers( quadratic_equation *equation );
void print_equation( quadratic_equation equation );
int input_coefficient(quadratic_equation *equation, int index);
