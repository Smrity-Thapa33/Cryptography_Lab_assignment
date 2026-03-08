#include <stdio.h>

int extendedGCD(int a, int b, int *x, int *y)
{
    if(b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main()
{
    int a, b, j, gcd, x, y;

    for(j = 1; j <= 3; j++)
    {
        printf("\nInput %d\n", j);

        printf("Enter value of a: ");
        scanf("%d", &a);

        printf("Enter value of b: ");
        scanf("%d", &b);

        gcd = extendedGCD(a, b, &x, &y);

        printf("GCD(%d, %d) = %d\n", a, b, gcd);
        printf("x = %d, y = %d\n", x, y);
        printf("Verification: %d*(%d) + %d*(%d) = %d\n", a, x, b, y, a*x + b*y);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 10");

    return 0;
}