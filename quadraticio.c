#include "quadraticio.h"


enum RETURN_VALUES input_coefficients( quadratic_equation *equation )
{
    assert(equation);
    assert(equation->roots);
    assert(equation->coefficients);

    printf("Enter coefficient a\n");
    while(!input_coefficient(&equation->coefficients[0]));

    printf("Enter coefficient b\n");
    while(!input_coefficient(&equation->coefficients[1]));

    printf("Enter coefficient c\n");
    while(!input_coefficient(&equation->coefficients[2]));

    if( isfinite(equation->coefficients[0]) &&
        isfinite(equation->coefficients[1]) &&
        isfinite(equation->coefficients[2]))
        return SUCCESS;

    printf(RED "Error during reading coefficients" WHITE);
    return ERROR;
}

enum RETURN_VALUES input_coefficient( double *coefficient_pointer )
{
    assert(coefficient_pointer);

    while (true)
    {
        if (scanf("%lg", coefficient_pointer) == COEFFICIENTS_AMOUNT)
        {
            if(!is_string_empty())
            {
                printf(RED "WARNING: UNEXPECTED INPUT\n" WHITE);
                clear_buffer();
            }

            if(isfinite(*coefficient_pointer))
                return SUCCESS;

            printf(RED "inappropriate coefficient, try again\n" WHITE);
            *coefficient_pointer = 0;

            return ERROR;
        }

        clear_buffer();
        printf(RED "invalid input, try again\n" WHITE);
    }
}

void print_answers( quadratic_equation *equation )
{
    assert(equation);
    assert(equation->roots);
    assert(equation->coefficients);

    printf(GREEN);

    printf("Equation %lgx^2%+lgx%+lg = 0\n",
                    equation->coefficients[0],
                    equation->coefficients[1],
                    equation->coefficients[2]);

    switch (equation->roots_number)
    {
        case NO_ROOTS:
            printf("no roots\n");
            break;
        case ONE_ROOT:
            printf("Root: %lg\n", equation->roots[0]);
            break;
        case TWO_ROOTS:
            printf("Roots: %lg, %lg\n", equation->roots[0], equation->roots[1]);
            break;
        case INF_ROOTS:
            printf("Roots: any number\n");
            break;
        default:
            printf("default\n");
            break;
    }

    printf(WHITE);

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

void fprint_equation( FILE *file, quadratic_equation equation )
{
    fprintf(file, "coefficients: %lg, %lg, %lg\n"
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

int input_coefficients_from_file( quadratic_equation *equations, FILE *input_address )
{
    int equations_number = 0;
    quadratic_equation *T = equations;
    printf("inputing from file...\n");
    while((fscanf(input_address, "%lg%lg%lg", T->coefficients, T->coefficients + 1, T->coefficients + 2) == 3))
    {

        equations_number++;
        T++;
    }

    return equations_number;
}

int save_solved_equations( quadratic_equation *equations, int equations_number )
{
    FILE *result_file = fopen("solved_equations.txt", "w");

    if (result_file == NULL)
        {
            printf("Cant open result file\n");
            return 0;
        }

    for(int i = 0; i < equations_number; i++)
        {

        fprintf(result_file, "\nEquation %d: ", i + 1);
        fprint_equation(result_file, equations[i]);
        }
    fclose(result_file);

    return equations_number;
}
