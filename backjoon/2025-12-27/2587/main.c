// 백준 2587번: 다섯 수의 평균과 중앙값 출력

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int sum = 0;
    int arr[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 5; j++)
        {
            if(arr[i] < arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printf("%d\n%d\n",sum/5,arr[2]);
}
