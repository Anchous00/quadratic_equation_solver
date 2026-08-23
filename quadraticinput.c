#include "quadratic.h"


int input_equations( quadratic_equation *equations )
{
    assert(equations);

    int equations_number = 0;
    char choice = '\0';

    printf("Enter f for reading from file, c for reading from console, any key for exit\n");
    choice = (char)getchar();

    switch (choice)
    {
    case 'f':
        equations_number = input_from_file(equations);
        break;

    case 'c':
        equations_number = input_from_console(equations);
        break;

    default:
        return 0;
        break;
    }

    if (equations_number == 0)
    {
        printf(RED "couldnt read any equations\n" WHITE);
    }

    clear_buffer();

    return equations_number;
}

int input_from_file( quadratic_equation *equations )
{//TODO input file format
    assert(equations);

    char file_name[MAX_FILE_NAME];

    printf("Enter file name:\n");
    scanf("%100s", file_name);//TODO почитать про формат ввода в scanf: example scanf("{%lf}", ......)
   // printf("%s%c", file_name, *(file_name + 12));

    FILE *input_address = fopen(file_name, "r");

    if (input_address == NULL)
    {
        printf("Error occurred during reading file\n");
        return ERROR;
    }

    int equations_number = read_coefficients_from_file(equations, input_address);
    printf("successful read %d equations from file %s\n", equations_number, file_name);

    if (fclose(input_address) != 0)
        printf(RED "WARNING: cant close file\n" WHITE);

    return equations_number;
}

int input_from_console( quadratic_equation *equations )
{
    assert(equations);

    int equations_number = read_coefficients_from_console(equations);

    printf("successful read %d equations from console\n", equations_number);

    return equations_number;
}

int read_coefficients_from_file( quadratic_equation *equations, FILE *input_address )//TODO объединить функции
{
    assert(equations);
    assert(input_address);

    int equations_number = 0;

    while((fscanf(input_address, "%lg%lg%lg",
                  equations->coefficients,
                  equations->coefficients + 1,
                  equations->coefficients + 2) == COEFFICIENTS_AMOUNT))
    {
        equations_number++;
        equations++;
    }

    return equations_number;
}

int read_coefficients_from_console( quadratic_equation *equations )
{
    assert(equations);

    printf("Enter coefficients a, b, c, any key for end\n");

    int equations_number = 0;

    while((scanf("%lg%lg%lg", equations->coefficients, equations->coefficients + 1, equations->coefficients + 2) == COEFFICIENTS_AMOUNT))
    {
        printf("Enter coefficients a, b, c, any key for end\n");

        equations_number++;
        equations++;
    }

    return equations_number;
}
