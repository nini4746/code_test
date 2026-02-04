#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NEG_INF (-1LL << 60)

static long long maxll(long long a, long long b)
{
	return (a > b) ? a : b;
}

int main(void)
{
	int N;
	int M;
	int i, j, k;
	int d1, d2, d3;
	int K;
	long long **map;
	long long ***dp_prev;
	long long ***dp_cur;
	long long answer;

	scanf("%d %d", &N, &M);

	map = (long long **)malloc(sizeof(long long *) * (size_t)N);
	for (i = 0; i < N; i++)
	{
		map[i] = (long long *)malloc(sizeof(long long) * (size_t)M);
		for (j = 0; j < M; j++)
			scanf("%lld", &map[i][j]);
	}

	K = N + M - 2;

	dp_prev = (long long ***)malloc(sizeof(long long **) * (size_t)N);
	dp_cur = (long long ***)malloc(sizeof(long long **) * (size_t)N);

	for (i = 0; i < N; i++)
	{
		dp_prev[i] = (long long **)malloc(sizeof(long long *) * (size_t)N);
		dp_cur[i] = (long long **)malloc(sizeof(long long *) * (size_t)N);
		for (j = 0; j < N; j++)
		{
			dp_prev[i][j] = (long long *)malloc(sizeof(long long) * (size_t)N);
			dp_cur[i][j] = (long long *)malloc(sizeof(long long) * (size_t)N);
		}
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				dp_prev[i][j][k] = NEG_INF;

	dp_prev[0][0][0] = map[0][0];

	for (k = 1; k <= K; k++)
	{
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				for (int t = 0; t < N; t++)
					dp_cur[i][j][t] = NEG_INF;

		for (int i1 = 0; i1 < N; i1++)
		{
			int j1 = k - i1;
			if (j1 < 0 || j1 >= M)
				continue;

			for (int i2 = 0; i2 < N; i2++)
			{
				int j2 = k - i2;
				if (j2 < 0 || j2 >= M)
					continue;

				for (int i3 = 0; i3 < N; i3++)
				{
					int j3 = k - i3;
					if (j3 < 0 || j3 >= M)
						continue;

					long long best_prev = NEG_INF;

					for (d1 = 0; d1 <= 1; d1++)
					{
						for (d2 = 0; d2 <= 1; d2++)
						{
							for (d3 = 0; d3 <= 1; d3++)
							{
								int pi1 = i1 - d1;
								int pi2 = i2 - d2;
								int pi3 = i3 - d3;

								if (pi1 < 0 || pi2 < 0 || pi3 < 0)
									continue;

								long long prev_val =
									dp_prev[pi1][pi2][pi3];

								best_prev = maxll(best_prev, prev_val);
							}
						}
					}

					if (best_prev == NEG_INF)
						continue;

					long long gain = map[i1][j1];

					if (!(i2 == i1 && j2 == j1))
						gain += map[i2][j2];

					if (!((i3 == i1 && j3 == j1) ||
						(i3 == i2 && j3 == j2)))
						gain += map[i3][j3];

					dp_cur[i1][i2][i3] = best_prev + gain;
				}
			}
		}

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				for (int t = 0; t < N; t++)
					dp_prev[i][j][t] = dp_cur[i][j][t];
	}

	answer = dp_prev[N - 1][N - 1][N - 1];
	printf("%lld\n", answer);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			free(dp_prev[i][j]);
			free(dp_cur[i][j]);
		}
		free(dp_prev[i]);
		free(dp_cur[i]);
		free(map[i]);
	}
	free(dp_prev);
	free(dp_cur);
	free(map);

	return 0;
}
