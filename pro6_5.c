/*
 * Demonstrate the use of a function with input and output parameters.
 */

#include <stdio.h>
#include <math.h>

void separate(double num, char *signp, int *wholep, double *fracp);

int
main(void)
{
    double value;
    char sn;
    int whl;
    double fr;

    /* get data */
    printf("Enter a value to analyze> ");
    scanf("%lf", &value);

    /* Separate data value into three parts */
    separate(value, &sn, &whl, &fr);

    /* Prints results */
    printf("Parts of %.4f\n sign: %c\n", value, sn);
    printf(" whole number magnitude: %d\n", whl);
    printf(" fractional part: %.4f\n", fr);

    return (0);
}

/*
 * Seperates a number into three parts: a sign ( +, -, or blank ),
 * a whole number magnitude, and a fractional part.
 * Pre: num is defined; signp, wholep, and fracp contain addresses of memory
 *      cells where results are to be stored.
 * Post: function results are stored in cells pointed to by signp, wholep, and fracp
 */

void
separate(double num,            /* input - value to be split                */
         char *signp,           /* output - sign of num                     */
         int *wholep,           /* output - whole number magnitude of num   */
         double *fracp)            /* output - fractional part of num          */
{
    double magnitude;
    /*Determines sign of num */
    if (num < 0)
        *signp = '-';
    else if (num == 0)
        *signp = ' ';
    else
        *signp = '+';

    /* Finds magnitude of num (its absolute value) and separate it into whole and fractional parts */
    magnitude = fabs(num);
    *wholep = floor(magnitude);
    *fracp = magnitude - *wholep;

}








