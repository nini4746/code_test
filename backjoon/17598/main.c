#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int t = 0;
    int l = 0;
    for (int i = 0; i < 9 ;i ++)
    {
        char str[6];
        scanf("%s",str);
        if(strlen(str) == 5)
            t++;
        else
            l++;
    }
    if (t < l)
        printf("%s","Lion");
    else
        printf("%s","Tiger");
}