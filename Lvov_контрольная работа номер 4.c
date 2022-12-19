#include <stdio.h>

int number(char c)
{
    return c >= '0' && c <= '9';
}
double polynom(const char *expr, double x)
{
    int coeffs[5] = { 0 };
    int power = 0;
    int coeff = 0;
    int coeffSign = 1;
    while(*expr)
    {
        if(*expr == '-')
            coeffSign = -1;
        if(number(*expr))
        {
            coeff *= 10;
            coeff += *expr - '0';
        }
        if(*expr == 'x')
        {
            if(*(expr + 1) == '^')
            {
                power = *(expr + 2) - '0';
                expr += 2;
            }
            else
                power = 1;

            coeffs[power] =  coeffSign * (coeff == 0 ? 1 : coeff);

            coeff = 0;
            coeffSign = 1;
        }
        expr++;
    }

    int f = 0;
    for(int i = 0; i < 5; i++)
    {
        double value = 1;
        for(int j = 0; j < i; j++)
            value *= x;
        f += value * coeffs[i];
    }

    return f;
}

int main()
{
    const char *expr = "x^3-2x^2+x";
    double x = 10;
    printf("y(%f)=%s returns %f", x, expr, polynom(expr, x));

}
