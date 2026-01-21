// 백준 12016번: 작업 시간 순으로 종료될 때 라운드 로빈 순서(완료 시각) 계산

#include <stdio.h>
#include <stdlib.h>

typedef struct s_job
{
	long long	time;
	int			idx;
}	t_job;

typedef struct s_bit
{
	int	n;
	int	*tree;
}	t_bit;

static t_bit	*bit_init(int n)
{
	t_bit	*b;

	b = (t_bit *)malloc(sizeof(t_bit));
	if (!b)
		return NULL;
	b->n = n;
	b->tree = (int *)calloc(n + 1, sizeof(int));
	if (!b->tree)
	{
		free(b);
		return NULL;
	}
	return b;
}

static void	bit_add(t_bit *b, int i, int v)
{
	while (i <= b->n)
	{
		b->tree[i] += v;
		i += (i & -i);
	}
}

static int	bit_sum(t_bit *b, int i)
{
	int	s;

	s = 0;
	while (i > 0)
	{
		s += b->tree[i];
		i -= (i & -i);
	}
	return s;
}

static int	cmp_job(const void *a, const void *b)
{
	const t_job	*x = (const t_job *)a;
	const t_job	*y = (const t_job *)b;

	if (x->time < y->time)
		return -1;
	if (x->time > y->time)
		return 1;
	if (x->idx < y->idx)
		return -1;
	if (x->idx > y->idx)
		return 1;
	return 0;
}

int	main(void)
{
	int			n;
	t_job		*jobs;
	long long	*ans;
	t_bit		*bit;
	long long	prev_time;
	long long	prefix;
	int			alive;
	int			i;

	if (scanf("%d", &n) != 1)
		return 0;

	jobs = (t_job *)malloc(sizeof(t_job) * n);
	ans = (long long *)calloc(n, sizeof(long long));
	if (!jobs || !ans)
		return 0;

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &jobs[i].time);
		jobs[i].idx = i;
	}

	qsort(jobs, n, sizeof(t_job), cmp_job);

	bit = bit_init(n);
	if (!bit)
		return 0;

	for (i = 1; i <= n; i++)
		bit_add(bit, i, 1);

	prev_time = 0;
	prefix = 0;
	alive = n;
	i = 0;

	while (i < n)
	{
		long long	cur;
		int			j;

		cur = jobs[i].time;

		if (cur > prev_time + 1)
			prefix += (cur - prev_time - 1) * (long long)alive;

		j = i;
		while (j < n && jobs[j].time == cur)
			j++;

		for (int k = i; k < j; k++)
		{
			int idx1 = jobs[k].idx + 1;
			int before = bit_sum(bit, idx1 - 1);
			ans[jobs[k].idx] = prefix + (long long)before + 1LL;
		}

		prefix += (long long)alive;
		for (int k = i; k < j; k++)
			bit_add(bit, jobs[k].idx + 1, -1);

		alive -= (j - i);
		prev_time = cur;
		i = j;
	}

	for (i = 0; i < n; i++)
		printf("%lld\n", ans[i]);

	free(bit->tree);
	free(bit);
	free(ans);
	free(jobs);
	return 0;
}
