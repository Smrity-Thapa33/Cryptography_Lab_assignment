#include <stdio.h>

long long mod_pow(long long base, long long exp, long long mod)
{
    long long res = 1;
    base = base % mod;
    while(exp > 0)
    {
        if(exp % 2 == 1)
            res = (res * base) % mod;
        exp /= 2;
        base = (base * base) % mod;
    }
    return res;
}

int main()
{
    long long p, g, x, y, k, M, a, b, decrypted;
    int j;

    for(j = 1; j <= 3; j++)
    {
        printf("\nInput %d\n", j);

        printf("Enter prime p: ");
        scanf("%lld", &p);

        printf("Enter generator g: ");
        scanf("%lld", &g);

        printf("Enter private key x: ");
        scanf("%lld", &x);

        y = mod_pow(g, x, p);
        printf("Public key y = %lld\n", y);

        printf("Enter message M (0 < M < %lld): ", p);
        scanf("%lld", &M);

        printf("Enter random k: ");
        scanf("%lld", &k);

        a = mod_pow(g, k, p);
        b = (mod_pow(y, k, p) * M) % p;

        decrypted = (b * mod_pow(a, p-1-x, p)) % p;

        printf("Encrypted message: a = %lld, b = %lld\n", a, b);
        printf("Decrypted message: M = %lld\n", decrypted);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 15");

    return 0;
}