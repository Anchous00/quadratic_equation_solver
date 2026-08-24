#include "quadratic.h"


void output_equations( quadratic_equation *equations, int equations_number )
{
    assert(equations);

    const char *file_name = "solved_equations.txt";
    char choice = '\0';

    printf("Enter f for saving in file, c for writing in console, any key for exit\n");
    FILE *output_file = fopen(file_name, "w");//TODO

    if (output_file == NULL)
    {
        printf("ERROR: cant open file");
        return;
    }

    choice = (char)getchar();

    switch (choice)
    {
    case 'f':
        save_solved_equations(equations, equations_number, output_file);
        break;

    case 'c':
        save_solved_equations(equations, equations_number, stdout);
        break;

    default:
        return;
        break;
    }

    return;
}

int save_solved_equations( quadratic_equation *equations, int equations_number, FILE *output_file )
{
    assert(equations);
    assert(output_file);

    for(int i = 0; i < equations_number; i++)
    {
        fprintf(output_file, "\nEquation %d: ", i + 1);
        fprint_equation(output_file, equations[i]);
    }

    printf(GREEN "successful saved %d solved equations in %s\n" WHITE, equations_number, "solved_equations.txt");

    if (fclose(output_file) != 0)
        printf(RED "WARNING: cant close file\n" WHITE);

    return equations_number;
}

void fprint_equation( FILE *file, quadratic_equation equation )
{
    assert(file);
    assert(equation.roots);
    assert(equation.coefficients);

    /*fprintf(file, "%lgx^2%+lgx%+lg = 0\n",
                    equation.coefficients[0] = 0 ?,
                    equation.coefficients[1],
                    equation.coefficients[2]);*/
    fprint_beautiful_equation( file, equation );


    switch (equation.roots_number)
    {
        case NO_ROOTS:
            fprintf(file, "no roots\n");
            break;
        case ONE_ROOT:
            fprintf(file, "Root: %lg\n", equation.roots[0]);
            break;
        case TWO_ROOTS:
            fprintf(file, "Roots: %lg, %lg\n", equation.roots[0], equation.roots[1]);
            break;
        case INF_ROOTS:
            fprintf(file, "Roots: any number\n");
            break;
        default:
            fprintf(file, "default\n");
            break;
    }

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

void fprint_beautiful_equation( FILE *output_file, quadratic_equation equation )
{
    assert(output_file);//TODO попробуй объединить

    if (is_zero(equation.coefficients[0]));

    else if (is_zero(equation.coefficients[0] - 1))
        fprintf(output_file, "x^2");

    else
        fprintf(output_file, "%lgx^2", equation.coefficients[0]);


    if (is_zero(equation.coefficients[1]));
        //fprintf(output_file, " ");

    else if (is_zero(equation.coefficients[1] - 1))
        fprintf(output_file, "+x");

    else
        fprintf(output_file, "%+lgx", equation.coefficients[1]);


    if (is_zero(equation.coefficients[2]));
        //fprintf(output_file, " ");

    else if (is_zero(equation.coefficients[2] - 1))
        fprintf(output_file, "+1");

    else
        fprintf(output_file, "%+lg", equation.coefficients[2]);



    if (is_zero(equation.coefficients[0]) && is_zero(equation.coefficients[1]) && is_zero(equation.coefficients[2]))
        fprintf(output_file, "0");

    fprintf(output_file, " = 0\n");

    return;
}
