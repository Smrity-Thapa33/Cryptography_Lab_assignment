#include <stdio.h>

int main()
{
    int n, i, j, flag;

    for(j = 1; j <= 3; j++)
    {
        printf("\nInput %d\n", j);

        printf("Enter a number: ");
        scanf("%d", &n);

        if(n <= 1)
        {
            printf("%d is NOT a prime number.\n", n);
            continue;
        }

        flag = 1;

        for(i = 2; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                flag = 0;
                break;
            }
        }

        if(flag == 1)
            printf("%d is a Prime number.\n", n);
        else
            printf("%d is NOT a Prime number.\n", n);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no:11");

    return 0;
}