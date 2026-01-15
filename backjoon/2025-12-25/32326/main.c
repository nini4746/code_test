#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int a, b, c;

    char s1[10], s2[10], s3[10];

    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",s3);

    a = atoi(s1);
    b = atoi(s2);
    c = atoi(s3);
    printf("%d",a * 3 + b * 4 + c * 5);
}