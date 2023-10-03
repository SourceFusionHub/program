/* Example using tan by TechOnTheNet.com */

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    /* Define temporary variables */
    double value;
    double result;

    /* Assign the value we will find the tan of */
    value = 0.5;

    /* Calculate the Tangent of value */
    result = tan(value);

    /* Display the result of the calculation */
    printf("The Tangent of %f is %f\n", value, result);

    return 0;
}
