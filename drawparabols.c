/*!
* \file
* \brief файл с функциями, отвечающими за отрисовку уравнений
*/
#include "TXLib.h"
#include "quadratic.h"
//! Ширина и высота окна
const int WIDTH = 800, HEIGHT = 600;
//! ГЛОБАЛЬНАЯ ПЕРЕМЕННАЯ ХРАНЯЩАЯ ЗНАЧЕНИЯ ПИКСЕЛЕЙ ОКНА
color field[HEIGHT][WIDTH] = {};

/*!
*\brief функция, заполняющая экран черным и рисующая оси
* \param [in] SCALE масштаб (количество пикселей на одну условную единицу длины)
* \param [in] xcntr координата нового центра экрана
* \param [in] ycntr координата нового центра экрана
*/
void initialize( double SCALE, double xcntr, double ycntr )
{
    for (int y = -HEIGHT/2; y < HEIGHT/2; y++)
    {
        for (int x = -WIDTH/2; x < WIDTH/2; x++)
        {
            putpixel(x, y, rgbBLACK);

            if (-x == (int)xcntr)
            {
                if (SCALE >= 1 && y % (int)SCALE == 0)
                    putpixel(x, y, rgbWHITE);
                else
                    putpixel(x, y, rgbRED);
            }

            if (-y == (int)ycntr)
            {
                if (SCALE >= 1 && x % (int)SCALE == 0)
                    putpixel(x, y, rgbWHITE);
                else
                    putpixel(x, y, rgbRED);
            }
        }
    }
}

/*!
* \brief функция отрисовки массива уравнений
* \param [in] equations массив уравнений
* \param [in] equations_number количество уравнений
* \details По нажатию стрелочек вправо/влево масштабируется отновсительно начала координат
* \details По нажатию стрелочек вверх/вниз масштабируется относительно текущего положения курсора
* \warning МАСШТАБИРОВАНИЕ ОТНОСИТЕЛЬНО КУРСОРА ОТВРАТИТЕЛЬНО ХУЕВОЕ
*/
void draw_equations( quadratic_equation *equations, int equations_number )
{
    assert(equations);

    double SCALE = 4;
    _txConsole = -1;
    txCreateWindow(WIDTH, HEIGHT);
    txSetFillColor(TX_WHITE);


    initialize(SCALE, 0, 0);

    for (int i = 0; i < equations_number; i++)
    {
        equations[i].clr = randRGB();
        add_parabol(equations + i, SCALE, 0, 0);
    }

    draw();

    while (!txGetAsyncKeyState(VK_ESCAPE))
    {
        if (txGetAsyncKeyState(VK_UP))
        {
            SCALE *= 2;
            initialize(SCALE, MouseX(), MouseY());

            for (int i = 0; i < equations_number; i++)
                add_parabol(equations + i, SCALE, MouseX(), MouseY());

            draw();
        }

        if (txGetAsyncKeyState(VK_DOWN))
        {
            SCALE /= 2;
            initialize(SCALE, MouseX(), MouseY());

            for (int i = 0; i < equations_number; i++)
                add_parabol(equations + i, SCALE, MouseX(), MouseY());

            draw();
        }

        if (txGetAsyncKeyState(VK_RIGHT))
        {
            SCALE *= 2;
            initialize(SCALE, 0, 0);

            for (int i = 0; i < equations_number; i++)
                add_parabol(equations + i, SCALE, 0, 0);

            draw();
        }

        if (txGetAsyncKeyState(VK_LEFT))
        {
            SCALE /= 2;
            initialize(SCALE, 0, 0);

            for (int i = 0; i < equations_number; i++)
                add_parabol(equations + i, SCALE, 0, 0);

            draw();
        }
    }

    return;
}

/*!
* \brief функция, добавляющая в field одно уравнение
* \param [in] equation уравнение
* \param [in] SCALE масштаб
* \param [in] xcntr координата нового центра экрана
* \param [in] ycntr координата нового центра экрана
*/
void add_parabol( quadratic_equation *equation, double SCALE, double xcntr, double ycntr )
{
    assert(equation);

    double a = equation->coefficients[0], b = equation->coefficients[1], c = equation->coefficients[2];

    for(int y = -HEIGHT/2; y < HEIGHT/2; y++)
    {
        for(int x = -WIDTH/2; x < WIDTH/2; x++)
        {
            double xscale = (xcntr + (double)x) / SCALE, yscale = (ycntr + (double)y) / SCALE;
            if (((znach(a, b, c, xscale) <= yscale)               && (znach(a, b, c, xscale + 1.0 / SCALE) >= yscale))               ||
                ((znach(a, b, c, xscale) <= yscale + 1.0 / SCALE) && (znach(a, b, c, xscale + 1.0 / SCALE) >= yscale + 1.0 / SCALE)) ||
                ((znach(a, b, c, xscale) >= yscale)               && (znach(a, b, c, xscale + 1.0 / SCALE) <= yscale + 1.0 / SCALE)))
            {
                putpixel(x, y, equation->clr);
            }
        }
    }

    return;
}

/*!
* \brief функция, вычисляющая значение квадратного многочлена в определенной точке
* \param [in] a коэффициент при х^2
* \param [in] b коэффициент при x
* \param [in] c свободный член
* \param [in] x точка, в которой вычисляется значение
* \return значение функции
*/
double znach( double a, double b, double c, double x )
{
    return a * (x) * (x) + b * (x) + c;
}

/*!
* \brief функция, добавляющая в field один пиксель
* \param [in] x координата x пикселя
* \param [in] y координата y пикселя
* \param [in] cl цвет пикселя
* \warning происходит перевод из системы координат, где 0;0 в левом верхнем углу и оси направлены вправо и вниз, в систему координат, где 0;0 в центре и оси направлены вправо и вверх
*/
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

/*!
* \brief функция отрисовки массива field
*/
void draw( void )
{
    txClear();
    txBegin();
    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            txSetPixel(x, y, RGB(field[y][x].R, field[y][x].G, field[y][x].B));
        }
    }
    // txTextOut(WIDTH - 20, HEIGHT/2, "x");
    // txTextOut(WIDTH/2 + 10, 0, "y");
    txEnd();
}

/*!
* \brief функция генерации случайного цвета
* \return случайный цвет
*/
color randRGB( void )
{
    return {(unsigned char)(rand() % 255), (unsigned char)(rand() % 255), (unsigned char)(rand() % 255)};
}

/*!
* \brief функция возвращающая координату курсора в нормальной системе координат
* \return х
*/
double MouseX( void )
{
    return txMouseX() - WIDTH/2;
}

/*!
* \brief функция возвращающая координату курсора в нормальной системе координат
* \return у
*/
double MouseY( void )
{
    return HEIGHT/2 - txMouseY() - 1;
}






//huy
