#include <stdio.h>
#include <math.h>

long long mod_pow(long long base, long long exp, long long mod)
{
    long long res = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return res;
}

int main()
{
    long long p, g, a, b, A, B, K1, K2;
    int j;

    for (j = 1; j <= 3; j++)
    {
        printf("\nInput %d\n", j);

        printf("Enter prime number p: ");
        scanf("%lld", &p);

        printf("Enter primitive root g: ");
        scanf("%lld", &g);

        printf("Enter private key a (User1): ");
        scanf("%lld", &a);

        printf("Enter private key b (User2): ");
        scanf("%lld", &b);

        A = mod_pow(g, a, p);
        B = mod_pow(g, b, p);

        K1 = mod_pow(B, a, p);
        K2 = mod_pow(A, b, p);

        printf("Public key A = %lld, B = %lld\n", A, B);
        printf("Shared secret key (User1) = %lld\n", K1);
        printf("Shared secret key (User2) = %lld\n", K2);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 13");

    return 0;
}