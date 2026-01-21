// 백준 29766번: 문자열에서 'DKSH' 패턴 등장 횟수 세기

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001];

    scanf("%s",str);

    int cnt = 0;
    for (int i = 0 ; i < strlen(str); i++)
    {
        if(str[i] == 'D' && i < strlen(str) - 3)
        {
            if(str[i + 1] == 'K' && str[i + 2] == 'S' && str[i + 3] == 'H')
                cnt++;
        } 
    }
    printf("%d",cnt);
}
