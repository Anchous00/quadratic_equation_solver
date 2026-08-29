/*!
* \file
* \brief заголовочный файл c макросами, енамами и прототипами функций из файлов quadraticsolver.c, quadraticinput.c, quadraticoutput.c
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
//! цвет в формате RGB, содержит три значения от 0 до 255
struct color
{
    unsigned char R = 0, G = 0, B = 0;
};

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
        ROOTS_NUMBER roots_number;
        //! цвет
        color clr;
};

//quadraticinput
int input_equations( quadratic_equation *equations );
int input_from_file( quadratic_equation *equations );
int input_from_console( quadratic_equation *equations );
int read_coefficients_from_file( quadratic_equation *equation, FILE *input_address );
int read_coefficients_from_console( quadratic_equation *equations );
int read_equations_from_file( quadratic_equation *equations, FILE *input_address );
ROOTS_NUMBER roots_number_from_string( const char *roots_number );

//quadraticoutput
void output_equations( quadratic_equation *equations, int equations_number );
void print_equation( quadratic_equation equation );
int save_solved_equations( quadratic_equation *equations, int equations_number, FILE *output_file );
void fprint_answer( FILE *output_file, quadratic_equation equation );
void fprint_beautiful_equation( FILE *output_file, quadratic_equation equation );
void fprint_solution( FILE *output_file, quadratic_equation *equation );

//quadraticsolver
void solve_quadratic_equation( quadratic_equation *equation );
void solve_linear_equation( quadratic_equation *equation );
RETURN_VALUES solve_equations( quadratic_equation *equations, int equations_number );

//drawparabols
#define rgbRED {255, 0, 0}
#define rgbGREEN {0, 255, 0}
#define rgbBLUE {0, 0, 255}
#define rgbBLACK {0, 0, 0}
#define rgbWHITE {255, 255, 255}


void draw_equations( quadratic_equation *equations, int equations_number );
void initialize( double SCALE );
void draw( void );
void add_parabol( quadratic_equation *equation, double SCALE );
void putpixel( int x, int y, color cl );
double znach( double a, double b, double c, double x );
color randRGB( void );






