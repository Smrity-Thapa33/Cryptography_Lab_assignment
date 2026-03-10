#include <stdio.h>

// Function to compute GCD
long long gcd(long long a, long long b)
{
    long long temp;
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Extended Euclidean Algorithm to find modular inverse
long long modInverse(long long e, long long phi)
{
    long long t = 0, newt = 1;
    long long r = phi, newr = e;
    long long quotient, temp;

    while(newr != 0)
    {
        quotient = r / newr;

        temp = t;
        t = newt;
        newt = temp - quotient * newt;

        temp = r;
        r = newr;
        newr = temp - quotient * newr;
    }

    if(r > 1) return -1; // Inverse doesn't exist
    if(t < 0) t += phi;
    return t;
}

// Modular exponentiation: (base^exp) % mod
long long mod_pow(long long base, long long exp, long long mod)
{
    long long res = 1;
    base = base % mod;

    while(exp > 0)
    {
        if(exp % 2 == 1)
            res = (res * base) % mod;

        exp = exp / 2;
        base = (base * base) % mod;
    }
    return res;
}

int main()
{
    long long p, q, n, phi, e, d, M, C, decrypted;
    int j;

    for(j = 1; j <= 3; j++)
    {
        printf("\nInput %d\n", j);

        printf("Enter prime number p: ");
        scanf("%lld", &p);

        printf("Enter prime number q: ");
        scanf("%lld", &q);

        n = p * q;
        phi = (p - 1) * (q - 1);

        printf("Enter public exponent e (1 < e < %lld and gcd(e,%lld)=1): ", phi, phi);
        scanf("%lld", &e);

        // Check if e is valid
        if(gcd(e, phi) != 1)
        {
            printf("Invalid e! It must be coprime with phi=%lld\n", phi);
            j--;
            continue;
        }

        d = modInverse(e, phi);
        if(d == -1)
        {
            printf("No modular inverse found! Try different e.\n");
            j--;
            continue;
        }

        printf("Enter message M (0 < M < %lld): ", n);
        scanf("%lld", &M);

        // Encryption
        C = mod_pow(M, e, n);
        // Decryption
        decrypted = mod_pow(C, d, n);

        printf("Public Key: (e=%lld, n=%lld)\n", e, n);
        printf("Private Key: d=%lld\n", d);
        printf("Encrypted Message: %lld\n", C);
        printf("Decrypted Message: %lld\n", decrypted);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 14");

    return 0;
}