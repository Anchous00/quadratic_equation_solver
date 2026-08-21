#include "utils.h"
#include "quadratic.h"

#include <assert.h>

int input_coefficients(quadratic_equation *equation)
{
    assert(equation);

    printf("Enter coefficient a\n");
    while(!input_coefficient(equation, 0));

    printf("Enter coefficient b\n");
    while(!input_coefficient(equation, 1));

    printf("Enter coefficient c\n");
    while(!input_coefficient(equation, 2));

    if( isfinite(equation->coefficients[0]) &&
        isfinite(equation->coefficients[1]) &&
        isfinite(equation->coefficients[2]))
        return SUCCESS;

    printf("\x1b[31mError during reading coefficients\x1b[0\nm");
    return ERROR;
}

int input_coefficient(quadratic_equation *equation, int index)
{
    while (true)
    {
        if (scanf("%lg", equation->coefficients + index) == COEFFICIENTS_AMOUNT)
        {
            if(!is_string_empty())
            {
                printf("\x1b[31mWARNING: UNEXPECTED INPUT\n\x1b[0m");
                clear_buffer();
            }

            if(isfinite(*(equation->coefficients + index)))
                return SUCCESS;

            printf("\x1b[31minappropriate coefficient, try again\x1b[0m\n");
            *(equation->coefficients + index) = 0;

            return ERROR;
        }

        clear_buffer();
        printf("\x1b[31minvalid input, try again\n\x1b[0m");
    }
}

void print_answers(quadratic_equation *equation)
{
    assert(equation);

    printf("\x1b[32m");

    switch (equation->roots_number)
    {
        case NO_ROOTS:
            printf("Equation %lgx^2 + %lgx + %lg\n",
                    equation->coefficients[0],
                    equation->coefficients[1],
                    equation->coefficients[2]);

            printf("no roots\n");
            break;
        case ONE_ROOT:
            printf("Equation %lgx^2 + %lgx + %lg\n",
                    equation->coefficients[0],
                    equation->coefficients[1],
                    equation->coefficients[2]);

            printf("Root: %lg\n", equation->roots[0]);
            break;
        case TWO_ROOTS:
            printf("Equation %lgx^2 + %lgx + %lg\n",
                    equation->coefficients[0],
                    equation->coefficients[1],
                    equation->coefficients[2]);

            printf("Roots: %lg, %lg\n", equation->roots[0], equation->roots[1]);
            break;
        case INF_ROOTS:
            printf("Equation %lgx^2 + %lgx + %lg\n",
                    equation->coefficients[0],
                    equation->coefficients[1],
                    equation->coefficients[2]);

            printf("Roots: any number\n");
            break;
        default:
            printf("default\n");
            break;
    }
    printf("\x1b[0m\n");
    return;
}


int solve_quadratic_equation( quadratic_equation *equation )
{
    assert(equation);

    if (is_zero(equation->coefficients[0]))
    {
        return solve_linear(equation);
    }

    double discriminant = equation->coefficients[1]*equation->coefficients[1] - 4*equation->coefficients[0]*equation->coefficients[2];

    if (discriminant < 0)
    {
        equation->roots_number = NO_ROOTS;
        equation->roots[0] = 0;
        equation->roots[1] = 0;
        return SUCCESS;
    }

    if (is_zero(discriminant))
    {
        equation->roots[0] = - equation->coefficients[1] / (2*equation->coefficients[0]);
        equation->roots[1] = 0;
        equation->roots_number = ONE_ROOT;
        return SUCCESS;
    }

    double square_root_of_discriminant = sqrt(discriminant);

    equation->roots[0] = (- equation->coefficients[1] + square_root_of_discriminant) / (2*equation->coefficients[0]);
    equation->roots[1] = (- equation->coefficients[1] - square_root_of_discriminant) / (2*equation->coefficients[0]);
    equation->roots_number = TWO_ROOTS;

    return SUCCESS;
}



void print_equation( quadratic_equation equation )//дебажная фигня
{
    printf("coefficients: %lg, %lg, %lg\n"
           "roots: %lg, %lg\n",
        equation.coefficients[0],
        equation.coefficients[1],
        equation.coefficients[2],
        equation.roots[0],
        equation.roots[1]
    );
}

int solve_linear(quadratic_equation *equation)
{
    if (is_zero(equation->coefficients[1]))
    {
        equation->roots_number = (is_zero((equation->coefficients)[2]) ? INF_ROOTS : NO_ROOTS);
        equation->roots[0] = 0;
        equation->roots[1] = 0;
        return SUCCESS;
    }
    equation->roots[0] = -equation->coefficients[2] / equation->coefficients[1];
    equation->roots[1] = 0;
    equation->roots_number = ONE_ROOT;
    return SUCCESS;
}
