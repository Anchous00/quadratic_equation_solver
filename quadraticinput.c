/*!
* \file
* \brief файл с функциями, отвечающими за ввод уравнений
*/

#include "quadratic.h"


/*!
*   \brief функция для выбора способа ввода уравнений
*   \param [in, out] equations массив для записи уравнений
*   \return количество записанных уравнений
*/
int input_equations( quadratic_equation *equations )
{
    assert(equations);

    int equations_number = 0;

    printf("Enter f for reading from file, c for reading from console, any key for exit\n");
    int choice = getchar();

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
    }

    if (equations_number == 0)
    {
        printf(RED "couldnt read any equations\n" WHITE);
    }

    clear_buffer();

    return equations_number;
}

/*!
*   \brief функция, начинающая ввод уравнений из файла
*   \param [in, out] equations массив для записи уравнений
*   \return количество записанных уравнений
*/
int input_from_file( quadratic_equation *equations )
{
    assert(equations);

    char file_name[MAX_FILE_NAME] = "";

    printf("Enter file name:\n");
    scanf("%100s", file_name);

    FILE *input_address = fopen(file_name, "r");
    if (input_address == NULL)
    {
        printf("Error occurred during reading file\n");
        return ERROR;
    }

    int equations_number = read_equations_from_file(equations, input_address);
    printf("successful read %d equations from file %s\n", equations_number, file_name);

    if (fclose(input_address) != 0)
        printf(RED "WARNING: cant close file\n" WHITE);

    return equations_number;
}

/*!
*   \brief функция, начинающая ввод уравнений из консоли
*   \param [in, out] equations массив для записи уравнений
*   \return количество записанных уравнений
*/
int input_from_console( quadratic_equation *equations )
{
    assert(equations);

    int equations_number = read_coefficients_from_console(equations);

    printf("successful read %d equations from console\n", equations_number);

    return equations_number;
}

/*!
*   \brief функция, читающая из файла коэффициенты уравнений через пробелы или пробельные символы
*   \param [in, out] equations массив для записи уравнений
*   \param [in] input_address файл для чтения
*   \return количество записанных уравнений
*/
int read_coefficients_from_file( quadratic_equation *equations, FILE *input_address )
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
        printf("equations_number: %d\n", equations_number);
    }

    return equations_number;
}

/*!
*   \brief функция, читающая из консоли коэффициенты уравнений через пробелы или пробельные символы
*   \param [in, out] equations массив для записи уравнений
*   \return количество записанных уравнений
*/
int read_coefficients_from_console( quadratic_equation *equations )
{
    assert(equations);

    printf(BLUE "Enter coefficients a, b, c, any key for end\n" WHITE);

    int equations_number = 0;

    while((scanf("%lg%lg%lg", equations->coefficients, equations->coefficients + 1, equations->coefficients + 2) == COEFFICIENTS_AMOUNT))
    {
        printf(BLUE "Enter coefficients a, b, c, any key for end\n" WHITE);

        equations_number++;
        equations++;
    }

    return equations_number;
}

/*!
*   \brief функция, читающая из файла уравнения в формате {a, b, c} {root1, root2, roots_number}
*   \param [in, out] equations массив для записи уравнений
*   \param [in] input_address файл для чтения
*   \return количество записанных уравнений
*/
int read_equations_from_file( quadratic_equation *equations, FILE *input_address )
{
    assert(equations);
    assert(input_address);

    int equations_number = 0;
    char roots_number[10] = "";

    while((fscanf(input_address, "{%lg, %lg, %lg} {%lg, %lg, %s }\n",
                  equations->coefficients,
                  equations->coefficients + 1,
                  equations->coefficients + 2,
                  equations->roots,
                  equations->roots + 1,
                  roots_number) == 6))
    {
        equations->roots_number = roots_number_from_string(roots_number);
        equations_number++;
        equations++;
    }

    return equations_number;
}

/*!
*   \brief функция расшифровывающая строку из файла в enum количества корней
*   \param [in, out] roots_number строка
*   \return соответствующее строке количество корней
*/
enum ROOTS_NUMBER roots_number_from_string(const char *roots_number)
{
    if (strcmp(roots_number, "NO_ROOTS") == 0)
        return NO_ROOTS;
    if (strcmp(roots_number, "ONE_ROOT") == 0)
        return ONE_ROOT;
    if (strcmp(roots_number, "TWO_ROOTS") == 0)
        return TWO_ROOTS;
    if (strcmp(roots_number, "INF_ROOTS") == 0)
        return INF_ROOTS;
    return NO_ROOTS;
}
