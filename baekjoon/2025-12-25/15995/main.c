// 백준 15995번: a의 모듈러 역원 x를 찾아 ax ≡ 1 (mod m) 만족하는 최소 x 출력

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
