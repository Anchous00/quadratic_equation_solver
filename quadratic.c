#include <stdio.h>
#include <math.h>
#include "utils.c"
enum ROOTS_NUMBER {
        NO_ROOTS,
        ONE_ROOT,
        TWO_ROOTS,
        INF_ROOTS};

struct quadratic_equation{
    double coefficients[3];
    double roots[2];
    int roots_number;
};

int quadratic_solver( quadratic_equation *equation );
int input_coefficients( quadratic_equation *equation );
void print_answers( quadratic_equation *equation );
void printeq( quadratic_equation equation );


int input_coefficients(quadratic_equation *equation)
{
    printf("Enter coefficients a, b, c\n");

    while (true)
    {
       // printeq(*equation);
        if (scanf("%lf %lf %lf", equation->coefficients, equation->coefficients + 1, equation->coefficients + 2) == 3)
        {
            //printf("%f%f%f\n",coefficients[0], coefficients[1], coefficients[2] );
           //  printeq(*equation);
            return 1;
        }
        clear_buffer();
        printf("invalid input, try again\n");
    }

    return 1;
}

void print_answers(quadratic_equation *equation)
{
    //printeq(*equation);
    switch (equation->roots_number)
    {
        case NO_ROOTS:
            printf("no roots :(\n");
            break;
        case ONE_ROOT:
            printf("Root: %f\n", equation->roots[0]);
            break;
        case TWO_ROOTS:
            printf("Roots: %f, %f\n", equation->roots[0], equation->roots[1]);
            break;
        case INF_ROOTS:
            printf("R\n");
            break;
        default:
            printf("bebebe\n");
    }
    printf("\n");
    return;
}

int quadratic_solver( quadratic_equation *equation )
{
    //printf("%f%f%f",coefficients[0], coefficients[1], coefficients[2]);
    if (is_zero(equation->coefficients[0]))
    {
        if (is_zero(equation->coefficients[1])){
            equation->roots_number = (is_zero((equation->coefficients)[2]) ? INF_ROOTS : NO_ROOTS);
            return 1;
        }
        equation->roots[0] = -equation->coefficients[1] / equation->coefficients[2];
        equation->roots_number = ONE_ROOT;
        return 1;
    }
    double discriminant = equation->coefficients[1]*equation->coefficients[1] - 4*equation->coefficients[0]*equation->coefficients[2];

    if (discriminant < 0)
    {
        equation->roots_number = NO_ROOTS;
        return 1;
    }

    if (is_zero(discriminant))
    {
        equation->roots[0] = - equation->coefficients[1] / (2*equation->coefficients[0]);
        equation->roots_number = ONE_ROOT;
        return 1;
    }
    double square_root_of_discriminant = sqrt(discriminant);
    equation->roots[0] = (- equation->coefficients[1] + square_root_of_discriminant) / (2*equation->coefficients[0]);
    equation->roots[1] = (- equation->coefficients[1] - square_root_of_discriminant) / (2*equation->coefficients[0]);
    equation->roots_number = TWO_ROOTS;
    return 1;
}

void printeq( quadratic_equation equation )
{
    printf("coefficients: %lf, %lf, %lf\nroots:%lf, %lf\n", equation.coefficients[0], equation.coefficients[1], equation.coefficients[2], equation.roots[0], equation.roots[1]);
}
