// 백준 2309번: 9명 중 합이 100인 일곱 난쟁이의 키 출력

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[9];
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - arr[i] - arr[j] == 100)
            {
                for(int k = 0; k < 9; k++)
                {
                    if(k != i && k != j)
                        printf("%d\n",arr[k]);
                }
                return (0);
            }
        }
    }
    return (0);
}
