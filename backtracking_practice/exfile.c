int	outside_top(int size, int **ysq, int coln, int expected)
{
	int	i;
	int	comp;
	int	max;

	comp = 0;
	max = 0;
	i = 0;
	while (i < size)
	{
		if (max < ysq[i][coln])
		{			
			max = ysq[i][coln];
			++comp;
		}
		++i;
	}
	if (comp != expected)
		return (0);
	return (1);
}

int	outside_floor(int size, int **ysq, int coln, int expected)
{
	int	i;
	int	comp;
	int	max;

	comp = 0;
	max = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (max < ysq[i][coln])
		{		
			max = ysq[i][coln];
			++comp;
		}
		--i;
	}
	if (comp != expected)
		return (0);
	return (1);
}

int	outside_left(int size, int **ysq, int row, int expected)
{
	int	i;
	int	comp;
	int	max;

	comp = 0;
	max = 0;
	i = 0;
	while (i < size)
	{
		if (max < ysq[row][i])
		{			
			max = ysq[row][i];
			++comp;
		}
		++i;
	}
	if (comp != expected)
		return (0);
	return (1);
}

int	outside_right(int size, int **ysq, int row, int expected)
{
	int	i;
	int	comp;
	int	max;

	comp = 0;
	max = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (max < ysq[row][i])
		{			
			max = ysq[row][i];
			++comp;
		}
		--i;
	}
	if (comp != expected)
		return (0);
	return (1);
}

int	inner_square(int size, int **ysq, int **input)
{
	int	i;
	int	j;
	int	correct;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			if (i == 0)
				correct = outside_top(size, ysq, j, input[i][j]);
			else if (i == 1)
				correct = outside_floor(size, ysq, j, input[i][j]);
			else if (i == 2)
				correct = outside_left(size, ysq, j, input[i][j]);
			else
				correct = outside_right(size, ysq, j, input[i][j]);
			if (!correct)
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}