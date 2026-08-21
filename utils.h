#include <stdio.h>
#include <math.h>
#include <assert.h>

#define RED "\x1b[31m"
#define WHITE "\x1b[0m"
#define GREEN "\x1b[32m"

enum ERROR_VALUES {
        SUCCESSFUL_ENDING = 0,
        ERROR_DURING_READING_COEFFICIENTS = 1,
        ERROR_OCCURED_DURING_READING_FILE = 2,
        ESCAPE = 3
};

enum RETURN_VALUES{
        ERROR = 0,
        SUCCESS = 1
};

void clear_buffer( void );
bool is_zero( double number );
void dont_close_console( void );
bool is_string_empty( void );
