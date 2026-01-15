#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s1[6], s2[6];

    scanf("%s %s",s1, s2);
    int a = atoi(s1);
    int m = atoi(s2);
    int i =0;
    for (;a * i % m != 1; i++);

    printf("%d", i);

}