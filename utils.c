const double EPSILON = 1e-16;


void clear_buffer( void );
int is_zero( double number );
void dont_close_console( void );

int is_zero( double number )
{
    return abs(number) < EPSILON;
}

void clear_buffer( void )
{
    while(getchar() != '\n');

    return;
}

void dont_close_console( void )
{
    getchar();
    getchar();

    return;
}
