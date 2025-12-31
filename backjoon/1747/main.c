#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_palindrome(int a)
{
    int origin = a;
    int rev = 0;

    while (a > 0)
    {
        rev = rev * 10 + (a % 10);
        a /= 10;
    }
    return origin == rev;
}

int main(void)
{
    int n;
    int limit;
    bool *is_prime;

    scanf("%d", &n);

    limit = 2000000;

    is_prime = calloc(limit + 1, sizeof(bool));
    for (int i = 2; i <= limit; i++)
        is_prime[i] = true;

    for (int i = 2; i * i <= limit; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }

    for (int x = n; x <= limit; x++)
    {
        if (is_prime[x] && is_palindrome(x))
        {
            printf("%d\n", x);
            break;
        }
    }

    free(is_prime);
    return 0;
}
