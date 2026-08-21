#include "quadratic.h"
#include "utils.h"

int is_zero( double number )
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

void dont_close_console( void )
{
    getchar();
    getchar();

    return;
}

int is_string_empty( void )
{
    char c = 0;
    while((c = (char)getchar()) == ' ')
        ;
    if(c == '\n' or c == EOF)
        return SUCCESS;
    return ERROR;
}
