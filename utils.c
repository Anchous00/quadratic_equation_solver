#include "utils.h"

const double EPSILON = 1e-8;

bool is_zero( double number )
{
    return fabs(number) < EPSILON;
}

void clear_buffer( void )
{
    char c = 0;

    while((c = (char)getchar()) != '\n' && c != EOF)
        ;

    return;
}

bool is_string_empty( void )
{
    char c = 0;

    while((c = (char)getchar()) == ' ')
        ;
    if(c == '\n' or c == EOF)
        return true;

    return false;
}

const char* error_text( enum ERROR_VALUES error_value )
{
    switch (error_value)
    {
        case SUCCESSFUL_ENDING:
            return "program ended successfully";

        case ERROR_DURING_READING_COEFFICIENTS:
            return "error occurred during reading coefficients";

        case ERROR_OCCURRED_DURING_READING_FILE:
            return "error occured during reading file";

        default:
            return "unknown error";
    }
}


