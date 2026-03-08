#include <stdio.h>

int main()
{
    int a, m, i, inverse, j, found;

    for(j = 1; j <= 3; j++)
    {
        printf("\nInput %d\n", j);

        printf("Enter integer a: ");
        scanf("%d", &a);

        printf("Enter modulus m: ");
        scanf("%d", &m);

        found = 0;

        for(i = 1; i < m; i++)
        {
            if((a * i) % m == 1)
            {
                inverse = i;
                found = 1;
                break;
            }
        }

        if(found)
            printf("Multiplicative inverse of %d mod %d is: %d\n", a, m, inverse);
        else
            printf("Multiplicative inverse does not exist.\n");
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 8");

    return 0;
}
