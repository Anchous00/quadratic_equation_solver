#include "quadratic.h"

//----------------------------------------------------------
//!
//!
//!
//----------------------------------------------------------
enum RETURN_VALUES solve_quadratic_equation( quadratic_equation *equation )
{
    assert(equation);
    assert(equation->roots);
    assert(equation->coefficients);
    assert(isfinite(equation->coefficients[0]));
    assert(isfinite(equation->coefficients[1]));
    assert(isfinite(equation->coefficients[2]));

    if (is_zero(equation->coefficients[0]))
    {
        return solve_linear_equation(equation);
    }

    double discriminant = equation->coefficients[1] * equation->coefficients[1]
                    - 4 * equation->coefficients[0] * equation->coefficients[2];

    if (is_zero(discriminant))
    {
        equation->roots[0] = -equation->coefficients[1] / (2 * equation->coefficients[0]);
        equation->roots[1] = NAN;
        equation->roots_number = ONE_ROOT;
        return SUCCESS;
    }

    if (discriminant < 0)
    {
        equation->roots_number = NO_ROOTS;
        equation->roots[0] = NAN;
        equation->roots[1] = NAN;
        return SUCCESS;
    }

    double square_root_of_discriminant = sqrt(discriminant);

    equation->roots[0] = ( -equation->coefficients[1] + square_root_of_discriminant)
                     / (2 * equation->coefficients[0]);
    equation->roots[1] = ( -equation->coefficients[1] - square_root_of_discriminant)
                     / (2 * equation->coefficients[0]);
    equation->roots_number = TWO_ROOTS;

    return SUCCESS;
}

enum RETURN_VALUES solve_linear_equation( quadratic_equation *equation )
{
    assert(equation);

    if (is_zero(equation->coefficients[1]))
    {
        equation->roots_number = (is_zero((equation->coefficients)[2]) ?INF_ROOTS : NO_ROOTS);
        equation->roots[0] = NAN;
        equation->roots[1] = NAN;

        return SUCCESS;
    }
    equation->roots[0] = -equation->coefficients[2] / equation->coefficients[1];
    equation->roots[1] = NAN;
    equation->roots_number = ONE_ROOT;

    return SUCCESS;
}

enum RETURN_VALUES solve_equations( quadratic_equation *equations, int equations_number )
{
    assert(equations);

    for(int i = 0; i < equations_number; i++)
    {
        solve_quadratic_equation(&equations[i]);
    }

    return SUCCESS;
}
