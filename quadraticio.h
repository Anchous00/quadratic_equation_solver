#include "utils.h"


enum ROOTS_NUMBER {
        NO_ROOTS  = 0,
        ONE_ROOT  = 1,
        TWO_ROOTS = 2,
        INF_ROOTS
};

const int COEFFICIENTS_AMOUNT = 1;
const int MAX_TEST_AMOUNT = 100;
const int MAX_FILE_NAME = 100;

struct quadratic_equation{
        double coefficients[3];
        double roots[2];
        enum ROOTS_NUMBER roots_number;
};

enum RETURN_VALUES input_coefficients( quadratic_equation *equation );
enum RETURN_VALUES input_coefficient( double *coefficient_pointer );
int input_coefficients_from_file( quadratic_equation *equation, FILE *input_address );
void print_answers( quadratic_equation *equation );
void print_equation( quadratic_equation equation );
int save_solved_equations( quadratic_equation *equations, int equations_number );
void fprint_equation( FILE *file, quadratic_equation equation );

