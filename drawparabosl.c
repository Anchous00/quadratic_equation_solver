#include "TXLib.h"
#include "quadratic.h"

const int WIDTH = 800, HEIGHT = 600;
color field[HEIGHT][WIDTH] = {};

// int main( void )
// {
//     initialize();
//
//     txCreateWindow(WIDTH, HEIGHT);
//     txSetFillColor(TX_WHITE);
//     txTextCursor (false);
//
//     input_and_draw_equations();
// }

void initialize( void )
{
    for(int y = -HEIGHT/2; y < HEIGHT/2; y++)
    {
        for(int x = -WIDTH/2; x < WIDTH/2; x++)
        {
            putpixel(x, y, rgbBLACK);
            if (x == 0)
                putpixel(x, y, rgbRED);
            if (y == 0)
                putpixel(x, y, rgbRED);
        }
    }
}

void draw_equations( quadratic_equation *equations, int equations_number, double SCALE )
{
    txCreateWindow(WIDTH, HEIGHT);
    txSetFillColor(TX_WHITE);
    txTextCursor (false);

    initialize();

    for (int i = 0; i < equations_number; i++)
        add_parabol(equations + i, SCALE, randRGB());

    draw();

    while (!txGetAsyncKeyState (VK_ESCAPE))
                {
                    if (txGetAsyncKeyState (VK_UP))
                    {
                        SCALE *= 2;
                        initialize();
                        for (int i = 0; i < equations_number; i++)
                            add_parabol(equations + i, SCALE, randRGB());
                        draw();
                    }
                    if (txGetAsyncKeyState (VK_DOWN))
                    {
                        SCALE /= 2;
                        initialize();
                        for (int i = 0; i < equations_number; i++)
                            add_parabol(equations + i, SCALE, randRGB());
                        draw();
                    }
                }

    return;
}

void add_parabol( quadratic_equation *equation, double SCALE, color clr )
{
    double a = equation->coefficients[0], b = equation->coefficients[1], c = equation->coefficients[2];

    for(int y = -HEIGHT/2; y < HEIGHT/2; y++)
    {
        for(int x = -WIDTH/2; x < WIDTH/2; x++)
        {
            double xscale = (double)x / SCALE, yscale = (double)y / SCALE;
            if ( ((znach(a, b, c, xscale) <= yscale) &&               (znach(a, b, c, xscale + 1.0 / SCALE) >= yscale)) ||
                 ((znach(a, b, c, xscale) <= yscale + 1.0 / SCALE) && (znach(a, b, c, xscale + 1.0 / SCALE) >= yscale + 1.0 / SCALE)) ||
                 ((znach(a, b, c, xscale) >= yscale) &&               (znach(a, b, c, xscale + 1.0 / SCALE) <= yscale + 1.0 / SCALE)))
            {
                putpixel(x, y, clr);
            }
        }
    }
}

double znach( double a, double b, double c, double x )
{
    return a * (x) * (x) + b * (x) + c;
}

void putpixel(int x, int y, color cl)
{
    if (abs(x) > WIDTH/2 || abs(y) > HEIGHT/2)
    {
        printf("out of field\n");
        return;
    }

    field[HEIGHT/2 - y - 1][x + WIDTH/2] = cl;

    return;
}

void draw( void )
{
    txClearConsole();
    txClear();
    txBegin();
    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            txSetPixel(x, y, RGB(field[y][x].R, field[y][x].G, field[y][x].B));
        }
    }
    txEnd();
}

color randRGB( void )
{
    return {(char)(rand() % 255), (char)(rand() % 255), (char)(rand() % 255)};
}


