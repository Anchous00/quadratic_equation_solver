#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1b[31m"
#define WHITE "\x1b[0m"
#define GREEN "\x1b[32m"

enum ERROR_VALUES {
        SUCCESSFUL_ENDING = 0,
        ERROR_DURING_READING_COEFFICIENTS = 1,
        ERROR_OCCURRED_DURING_READING_FILE = 2,
};

enum RETURN_VALUES{
        ERROR = 0,
        SUCCESS = 1
};

void clear_buffer( void );
bool is_zero( double number );
bool is_string_empty( void );
const char* error_text( enum ERROR_VALUES error_value );







//TODO
/*
result = SolveEquation();

switch (result)
{
case SUCCESSFUL_ENDING:
        fprintf(f, "все хорошо");
        break;

}


result = SolveEquation();

switch (result)
{
case SUCCESSFUL_ENDING:
        MakeWindow("все хорошо");
        break;
}


result = SolveEquation();

switch (result)
{
case SUCCESSFUL_ENDING:
        printf("все хорошо");
        break;
}
*/
