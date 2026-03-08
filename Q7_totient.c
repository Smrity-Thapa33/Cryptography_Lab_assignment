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
    int n, i, count, j;

    for(j = 1; j <= 3; j++)
    {
        printf("\nInput %d\n", j);

        printf("Enter a number: ");
        scanf("%d", &n);

        count = 0;

        for(i = 1; i < n; i++)
        {
            if(gcd(n, i) == 1)
            {
                count++;
            }
        }

        printf("Totient (phi) of %d is: %d\n", n, count);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 7");

    return 0;
}