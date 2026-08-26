#include "utils.h"

/*!
* \file
* \brief файл с полезными в работе функциями
*/

/*!
* \brief погрешность, в пределах которой два числа с плавающей точкой считаются равными
*/
const double EPSILON = 1e-8;

/*!
* \brief функция сравнения числа с плавающей точкой с нулем
* \param [in] number число для сравнения
* \return true если число 0 иначе false
*/
bool is_zero( double number )
{
    return fabs(number) < EPSILON;
}

/*!
* \brief функция которая съедает все символы в буффере до новой строки
*/
void clear_buffer( void )
{
    char c = 0;

    while((c = (char)getchar()) != '\n' && c != EOF)
        ;

    return;
}

/*!
* \brief функция сообщающая о наличии символов в буффере
* \return true если буффер пуст иначе false
*/
bool is_string_empty( void )
{
    char c = 0;

    while((c = (char)getchar()) == ' ')
        ;
    if(c == '\n' or c == EOF)
        return true;

    return false;
}

/*!
* \brief функция, возваращающая большее из двух чисел
* \param [in] x1 число 1
* \param [in] x2 число 2
* \return большее из чисел
*/
double max( double x1, double x2 )
{
    return x1 > x2 ? x1 : x2;
}

/*!
* \brief функция, возваращающая меньшее из двух чисел
* \param [in] x1 число 1
* \param [in] x2 число 2
* \return меньшее из чисел
*/
double min( double x1, double x2 )
{
    return x1 < x2 ? x1 : x2;
}


const char* error_text( enum ERROR_VALUES error_value )
{
    switch (error_value)
    {
        case SUCCESSFUL_ENDING:
            return "program ended successfully";

        case ERROR_DURING_READING_COEFFICIENTS:
            return "error occurred during reading coefficients";

        case ERROR_OCCURRED_DURING_READING_FILE:
            return "error occured during reading file";

        default:
            return "unknown error";
    }
}
