/*!
* \file
* \brief файл с функциями, отвечающими за вывод уравнений
*/

#include "quadratic.h"

//! захардкоженное имя файла для записи
const char *output_file_name = "solved_equations.txt";

/*!
* \brief функция выбора пути вывода решенных уравнений
* \param [in] equations уравнения для вывода
* \param [in] equations_number количество уравнений
*/
void output_equations( quadratic_equation *equations, int equations_number )
{
    assert(equations);

    if (equations_number == 0)
        return;

    printf("Enter f for saving in file, c for writing in console, d for drawing graphiks, any key for exit\n");

    char choice = (char)getchar();

    switch (choice)
    {
        case 'f':
        {
            FILE *output_file = fopen(output_file_name, "w");

            if (output_file == NULL)
            {
                printf("ERROR: cant open file");
                return;
            }
            save_solved_equations(equations, equations_number, output_file);

            if (fclose(output_file) != 0)
                printf(RED "WARNING: cant close file\n" WHITE);
            break;
        }

    case 'c':
        save_solved_equations(equations, equations_number, stdout);
        break;

    case 'd':
        draw_equations(equations, equations_number);
        break;

    default:
        return;
        break;
    }

    return;
}

/*!
* \brief функция для сохранения уравнений в файл
* \param [in] equations уравнения для вывода
* \param [in] equations_number количество уравнений
* \param [in] output_file файл для записи
* \note если выбран вывод в консоль, как output_file передается stdin
*/
int save_solved_equations( quadratic_equation *equations, int equations_number, FILE *output_file )
{
    assert(equations);
    assert(output_file);

    for(int i = 0; i < equations_number; i++)
    {
        fprintf(output_file, "Equation %d: ", i + 1);
        fprint_beautiful_equation(output_file, equations[i]);
        fprint_solution(output_file, &equations[i]);
        fprint_answer(output_file, equations[i]);
    }

    printf(GREEN "successful saved %d solved equations in %s\n" WHITE, equations_number, "solved_equations.txt");

    return equations_number;
}

/*!
* \brief функция для сохранения записи ответа на уравнение в файл
* \param [in] equation уравнение для вывода
* \param [in] output_file файл для записи
*/
void fprint_answer( FILE *output_file, quadratic_equation equation )
{
    assert(output_file);
    assert(equation.roots);
    assert(equation.coefficients);

    switch (equation.roots_number)
    {
        case NO_ROOTS:
            fprintf(output_file, "no roots\n");
            break;
        case ONE_ROOT:
            fprintf(output_file, "Root: %lg\n", equation.roots[0]);
            break;
        case TWO_ROOTS:
            fprintf(output_file, "Roots: %lg, %lg\n", equation.roots[0], equation.roots[1]);
            break;
        case INF_ROOTS:
            fprintf(output_file, "Roots: any number\n");
            break;
        default:
            fprintf(output_file, "default\n");
            break;
    }

    fprintf(output_file, "\n");

    return;

}

void print_equation( quadratic_equation equation )//дебажная фигня
{
    printf("coefficients: %lg, %lg, %lg\n"
           "%d roots: %lg, %lg\n",
        equation.coefficients[0],
        equation.coefficients[1],
        equation.coefficients[2],
        equation.roots_number,
        equation.roots[0],
        equation.roots[1]
    );

    return;
}

/*!
* \brief функция для красивой записи условия уравнения в файл
* \param [in] equation уравнение для вывода
* \param [in] output_file файл для записи
*/
void fprint_beautiful_equation( FILE *output_file, quadratic_equation equation )
{
    assert(output_file);

    if (is_zero(equation.coefficients[0]))
        ;

    else if (is_zero(equation.coefficients[0] - 1))
        fprintf(output_file, "x^2");

    else if (is_zero(equation.coefficients[0] + 1))
        fprintf(output_file, "-x^2");

    else
        fprintf(output_file, "%lgx^2", equation.coefficients[0]);



    if (is_zero(equation.coefficients[1]))
        ;

    else if (is_zero(equation.coefficients[1] - 1))
        fprintf(output_file, is_zero(equation.coefficients[0]) ? "x" : "+x");

    else if (is_zero(equation.coefficients[1] + 1))
        fprintf(output_file, "-x");

    else
        fprintf(output_file, "%+lgx", equation.coefficients[1]);



    if (is_zero(equation.coefficients[2]))
        ;

    else if (is_zero(equation.coefficients[2] - 1))
        fprintf(output_file, "+1");

    else
        fprintf(output_file, "%+lg", equation.coefficients[2]);


    if (is_zero(equation.coefficients[0]) &&
        is_zero(equation.coefficients[1]) &&
        is_zero(equation.coefficients[2]))
        fprintf(output_file, "0");

    fprintf(output_file, " = 0\n");

    return;
}

/*!
* \brief функция для записи решения уравнения в файл
* \param [in] equation уравнение для вывода
* \param [in] output_file файл для записи
*/
void fprint_solution( FILE *output_file, quadratic_equation *equation )
{
    assert(output_file);
    assert(equation);
    assert(equation->roots);
    assert(equation->coefficients);

    fprintf(output_file, "Solution:\n");

    if (is_zero(equation->coefficients[0]))
    {
        if (is_zero(equation->coefficients[1]))
        {
            fprintf(output_file, "%s", is_zero(equation->coefficients[2]) ? "Any number fit in this equation\n" : "No number fit in this equation\n");
            return;
        }
        fprintf(output_file, "linear equation, coefficients a = %lg, b = %lg\nroot x = -b / a = %-lg / %lg\n",
                equation->coefficients[1], equation->coefficients[2],
                -equation->coefficients[2], equation->coefficients[1]);

        return;
    }
    fprintf(output_file, "coefficients: a = %lg, b = %lg, c = %lg\n",
            equation->coefficients[0],
            equation->coefficients[1],
            equation->coefficients[2]);

    double discriminant = calc_discriminant(equation->coefficients[0],
                                       equation->coefficients[1],
                                       equation->coefficients[2]);

    fprintf(output_file, "Discriminant D = b * b - 4 * a * c = %lg * %lg - 4 * %lg * %lg = %lg\n",
           equation->coefficients[1],
           equation->coefficients[1],
           equation->coefficients[0],
           equation->coefficients[2],
           discriminant);

    if (is_zero(discriminant))
    {
        fprintf(output_file, "D = 0, one root x1 = -b / (2 * a) = %+lg/(2 * (%lg))\n",
              -equation->coefficients[1], equation->coefficients[0]);
        return;
    }

    if (discriminant < 0)
    {
        fprintf(output_file, "D < 0, equation has no roots\n");
        return;
    }

    fprintf(output_file, "D > 0, two roots:\n"
            "x1 = (-b + sqrt(D))/(2 * a) = (%-lg + sqrt(%lg))/(2 * %lg)\n"
            "x2 = (-b - sqrt(D))/(2 * a) = (%-lg - sqrt(%lg))/(2 * %lg)\n",
            -equation->coefficients[1],
            discriminant,
            equation->coefficients[0],
            -equation->coefficients[1],
            discriminant,
            equation->coefficients[0]);

    return;
}
