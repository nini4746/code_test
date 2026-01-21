// 백준 32326번: 세 수에 3·4·5 가중치를 곱해 합을 출력

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
