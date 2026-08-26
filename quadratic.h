/*!
* \file
* \brief заголовочный файл макросами, енамами и прототипами функций из файлов quadraticsolver.c, quadraticinput.c, quadraticoutput.c
*/

#include "utils.h"
/*!
* \brief количество корней уравнения
* \note 3 это бесконечность
*/
enum ROOTS_NUMBER {
        NO_ROOTS  = 0,
        ONE_ROOT  = 1,
        TWO_ROOTS = 2,
        INF_ROOTS = 3
};
//! количество коэффициентов уравнения
const int COEFFICIENTS_AMOUNT  = 3;
//! максимальное количество уравнений которое может ввести пользователь
const int MAX_EQUATIONS_AMOUNT = 100;
//! максимальное количество тестовых уравнений
const int MAX_TEST_AMOUNT      = 100;
//! максимальная длина имени файла
const int MAX_FILE_NAME        = 100;
/*!
 *  \brief     структура квадратного уравнения
 *  \details   содержит массив коэффициентов, массив корней и переменную количества корней
 */
struct quadratic_equation {
        //! массив коэффициентов
        double coefficients[3];
        //! массив корней
        double roots[2];
        //! количество корней
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
void fprint_answer( FILE *output_file, quadratic_equation equation );
void fprint_beautiful_equation( FILE *output_file, quadratic_equation equation );
void fprint_solution( FILE *output_file, quadratic_equation *equation );

//quadraticsolver фтв онг
void solve_quadratic_equation( quadratic_equation *equation );
void solve_linear_equation( quadratic_equation *equation );
enum RETURN_VALUES solve_equations( quadratic_equation *equations, int equations_number );





