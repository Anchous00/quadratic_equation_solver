/*!
* \file
* \brief заголовочный файл макросами, енамами и прототипами функций из файла utils.c
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1b[31m"
#define WHITE "\x1b[0m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"

enum ERROR_VALUES {
        SUCCESSFUL_ENDING = 0,
        ERROR_DURING_READING_COEFFICIENTS = 1,
        ERROR_OCCURRED_DURING_READING_FILE = 2,
};

enum RETURN_VALUES{
        MYERROR = 0,
        MYSUCCESS = 1
};

void clear_buffer( void );
bool is_string_empty( void );
bool is_zero( double number );
const char* error_text( ERROR_VALUES error_value );
double calc_discriminant( double a, double b, double c );
double max( double x1, double x2 );
double min( double x1, double x2 );

