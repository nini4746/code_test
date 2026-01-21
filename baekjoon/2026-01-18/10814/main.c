// 백준 10814번: 나이순으로 정렬하되 같은 나이는 입력 순서를 유지

#include <stdio.h>
#include <stdlib.h>

typedef struct s_member
{
	int age;
	char name[101];
}t_member;

int compare(const void *a, const void *b)
{
    const t_member *x = (const t_member *)a;
    const t_member *y = (const t_member *)b;

    if (x->age < y->age)
        return -1;
    if (x->age > y->age)
        return 1;
    return 0;	
}


int main(void)
{
	int n;

	scanf("%d", &n);

	t_member *arr = calloc(n, sizeof(t_member));

	for (int i = 0; i < n; i++)
		scanf("%d %s", &arr[i].age, arr[i].name);

	qsort(arr, n, sizeof(t_member), compare);

	for (int i = 0; i < n; i++)
		printf("%d %s\n", arr[i].age, arr[i].name);
}
