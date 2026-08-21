#include "utils.h"

const double EPSILON = 1e-32;

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
