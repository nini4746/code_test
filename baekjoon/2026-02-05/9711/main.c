#include <stdio.h>

int main(void)
{
	int T;
	int P;
	long long Q;
	int case_num;
	long long prev;
	long long curr;
	long long next;
	int i;

	scanf("%d", &T);

	case_num = 1;
	while (case_num <= T)
	{
		scanf("%d %lld", &P, &Q);

		if (P == 1 || P == 2)
		{
			printf("Case #%d: %lld\n", case_num, 1 % Q);
		}
		else
		{
			prev = 1;
			curr = 1;

			i = 3;
			while (i <= P)
			{
				next = (prev + curr) % Q;
				prev = curr;
				curr = next;
				i++;
			}

			printf("Case #%d: %lld\n", case_num, curr);
		}

		case_num++;
	}

	return 0;
}
