#include <stdio.h>
#include <stdlib.h>

long long power(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y % 2 == 1)
            res = (res * x) % p;

        y = y / 2;
        x = (x * x) % p;
    }

    return res;
}

int millerTest(long long d, long long n)
{
    long long a = 2 + rand() % (n - 4);
    long long x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return 1;

    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return 0;

        if (x == n - 1)
            return 1;
    }

    return 0;
}

int isPrime(long long n, int k)
{
    if (n <= 1 || n == 4)
        return 0;
    if (n <= 3)
        return 1;

    long long d = n - 1;

    while (d % 2 == 0)
        d /= 2;
	int i;
    for (i = 0; i < k; i++)
        if (!millerTest(d, n))
            return 0;

    return 1;
}

int main()
{
    long long n;
    int j;

    for (j = 1; j <= 3; j++)
    {
        printf("\nInput %d\n", j);

        printf("Enter number to test: ");
        scanf("%lld", &n);

        if (isPrime(n, 5))
            printf("%lld is probably a Prime number.\n", n);
        else
            printf("%lld is a Composite number.\n", n);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 12");

    return 0;
}
