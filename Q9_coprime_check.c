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

        printf("Enter first number: ");
        scanf("%d", &a);

        printf("Enter second number: ");
        scanf("%d", &b);

        result = gcd(a, b);

        if(result == 1)
            printf("%d and %d are Coprime numbers.\n", a, b);
        else
            printf("%d and %d are NOT Coprime numbers.\n", a, b);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 9");

    return 0;
}