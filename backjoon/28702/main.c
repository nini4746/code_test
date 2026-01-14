#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char s[10];
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", s);

        if (isdigit(s[0]))
        {
            int ans = atoi(s) + 3 - i;
            if (ans % 3 == 0 && ans % 5 == 0)
            {
                printf("FizzBuzz");
                return (0);
            }
            if (ans % 3 == 0)
            {
                printf("Fizz");
                return (0);
            }
            if (ans % 5 == 0)
            {
                printf("Buzz");
                return (0);
            }
            else
            {
                printf("%d", ans);
                return (0);
            }
        }
    }
}