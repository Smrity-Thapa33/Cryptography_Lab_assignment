#include <stdio.h>

int gcd(int a, int b)
{
    int temp;
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a, b, j, result;

    for(j = 1; j <= 3; j++)
    {
        printf("\nInput %d\n", j);

        printf("Enter first integer: ");
        scanf("%d", &a);

        printf("Enter second integer: ");
        scanf("%d", &b);

        result = gcd(a, b);

        printf("GCD of %d and %d is: %d\n", a, b, result);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 6");

    return 0;
}