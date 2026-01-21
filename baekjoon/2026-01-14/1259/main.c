// 백준 1259번: 여러 수에 대해 팰린드롬인지 판별

#include <stdio.h>
#include <string.h>

int main(void)
{
    while (1)
    {
        char s[7];
        
        scanf("%s", s);
        if (s[0] == '0')
            return (0);
        int len = strlen(s);

        int f = 0;
        int l = len - 1;

        for (;f < l;)
        {
            if (s[f] != s[l])
            {
                printf("no\n");
                break;
            }

            f++;
            l--;
        }
        if (f >= l)
            printf("yes\n");
    }
}
