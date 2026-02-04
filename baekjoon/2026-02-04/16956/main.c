#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int R;
	int C;
	char **map;
	int i;
	int j;
	int ok;

	scanf("%d %d", &R, &C);

	map = (char **)malloc(sizeof(char *) * R);
	if (map == NULL)
		return (0);

	i = 0;
	while (i < R)
	{
		map[i] = (char *)malloc(sizeof(char) * (C + 1));
		if (map[i] == NULL)
			return (0);
		scanf("%s", map[i]);
		i++;
	}

	ok = 1;
	i = 0;
	while (i < R && ok)
	{
		j = 0;
		while (j < C)
		{
			if (map[i][j] == 'W')
			{
				if (i > 0 && map[i - 1][j] == 'S')
					ok = 0;
				if (i + 1 < R && map[i + 1][j] == 'S')
					ok = 0;
				if (j > 0 && map[i][j - 1] == 'S')
					ok = 0;
				if (j + 1 < C && map[i][j + 1] == 'S')
					ok = 0;
			}
			j++;
		}
		i++;
	}

	if (!ok)
	{
		printf("0\n");
	}
	else
	{
		printf("1\n");
		i = 0;
		while (i < R)
		{
			j = 0;
			while (j < C)
			{
				if (map[i][j] == '.')
					map[i][j] = 'D';
				j++;
			}
			printf("%s\n", map[i]);
			i++;
		}
	}

	i = 0;
	while (i < R)
	{
		free(map[i]);
		i++;
	}
	free(map);

	return (0);
}
