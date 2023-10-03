#include <stdio.h>

double powerofnum(double n,double p)
{
    double result=1.000000;
    for(int i=1;i<=p;i++)
    {
        result=result*n;
    }
    return result;
}
int main()
{
  double number,power;
  printf("Enter a number: ");
  scanf("%lf",&number);
  printf("Enter the power of the number: ");
  scanf("%lf",&power);
  double result=powerofnum(number,power);
  printf("\nThe answer is %f",result);
}
