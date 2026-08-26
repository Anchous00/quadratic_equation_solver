#include "utils.h"
//quadraticio.h
enum ROOTS_NUMBER {
        NO_ROOTS  = 0,
        ONE_ROOT  = 1,
        TWO_ROOTS = 2,
        INF_ROOTS
};

const int COEFFICIENTS_AMOUNT  = 3;
const int MAX_EQUATIONS_AMOUNT = 100;
const int MAX_TEST_AMOUNT      = 100;
const int MAX_FILE_NAME        = 100;

struct quadratic_equation {
        double coefficients[3];
        double roots[2];
        enum ROOTS_NUMBER roots_number;
};

//quadraticinput
int input_equations( quadratic_equation *equations );
int input_from_file( quadratic_equation *equations );
int input_from_console( quadratic_equation *equations );
int read_coefficients_from_file( quadratic_equation *equation, FILE *input_address );
int read_coefficients_from_console( quadratic_equation *equations );
int read_equations_from_file( quadratic_equation *equations, FILE *input_address );
enum ROOTS_NUMBER roots_number_from_string(const char *roots_number);

//quadraticoutput
void output_equations( quadratic_equation *equations, int equations_number );
void print_equation( quadratic_equation equation );
int save_solved_equations( quadratic_equation *equations, int equations_number, FILE *output_file );
void fprint_answer( FILE *file, quadratic_equation equation );
void fprint_beautiful_equation( FILE *output_file, quadratic_equation equation );
void fprint_solution( FILE *file, quadratic_equation *equation );


//quadraticsolver.h
enum RETURN_VALUES solve_quadratic_equation( quadratic_equation *equation );
enum RETURN_VALUES solve_linear_equation( quadratic_equation *equation );
enum RETURN_VALUES solve_equations( quadratic_equation *equations, int equations_number );





