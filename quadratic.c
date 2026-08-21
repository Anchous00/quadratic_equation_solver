#include "quadratic.h"
//TODO выбор ввода из файла или stdin  для базовой проги + возможность сохранить результаты в файл
enum RETURN_VALUES solve_quadratic_equation( quadratic_equation *equation )
{
    assert(equation);
    assert(equation->roots);
    assert(equation->coefficients);

    if (is_zero(equation->coefficients[0]))
    {
        return solve_linear_equation(equation);
    }

    double discriminant = equation->coefficients[1] * equation->coefficients[1] - 4 * equation->coefficients[0] * equation->coefficients[2];

     if (is_zero(discriminant))
    {
        equation->roots[0] = -equation->coefficients[1] / (2 * equation->coefficients[0]);
        equation->roots[1] = 0;
        equation->roots_number = ONE_ROOT;
        return SUCCESS;
    }

    if (discriminant < 0)
    {
        equation->roots_number = NO_ROOTS;
        equation->roots[0] = 0;
        equation->roots[1] = 0;
        return SUCCESS;
    }

    double square_root_of_discriminant = sqrt(discriminant);

    equation->roots[0] = ( -equation->coefficients[1] + square_root_of_discriminant) / (2 * equation->coefficients[0]);
    equation->roots[1] = ( -equation->coefficients[1] - square_root_of_discriminant) / (2 * equation->coefficients[0]);
    equation->roots_number = TWO_ROOTS;

    return SUCCESS;
}

enum RETURN_VALUES solve_linear_equation( quadratic_equation *equation )
{
    if (is_zero(equation->coefficients[1]))
    {
        equation->roots_number = (is_zero((equation->coefficients)[2]) ?INF_ROOTS : NO_ROOTS);
        equation->roots[0] = 0;
        equation->roots[1] = 0;

        return SUCCESS;
    }
    equation->roots[0] = -equation->coefficients[2] / equation->coefficients[1];
    equation->roots[1] = 0;
    equation->roots_number = ONE_ROOT;

    return SUCCESS;
}

enum RETURN_VALUES input_from_file( void )
{
    quadratic_equation test_equations[MAX_TEST_AMOUNT];
    char file_name[MAX_FILE_NAME];

    printf("Enter file name:\n");
    scanf("%s", file_name);

    FILE *input_address = fopen(file_name, "r");

    if (input_address == NULL)
    {
        printf("Error occured during reading file\n");
        return ERROR;
    }

    int equations_number = input_coefficients_from_file(test_equations, input_address);
    printf("successful read %d equations\n", equations_number);
    fclose(input_address);

    for(int i = 0; i < equations_number; i++)
        {
        solve_quadratic_equation(&test_equations[i]);
        }

    save_solved_equations( test_equations, equations_number );

    return SUCCESS;
}




