#include<stdio.h>
int main()
{
    int a,b;
    char c;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("Enter the operator: ");
    scanf(" %c",&c);
    switch(c)
    {
        case '+':
            printf("The sum of %d and %d is %d",a,b,a+b);
            break;
        case '-':
            printf("The difference of %d and %d is %d",a,b,a-b);
            break;
        case '*':
            printf("The product of %d and %d is %d",a,b,a*b);
            break;
        case '/':
            printf("The quotient of %d and %d is %d",a,b,a/b);
            break;
        default:
            printf("Invalid operator");
    }
    return 0;
}