/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:13:42 by klew              #+#    #+#             */
/*   Updated: 2022/01/16 18:19:03 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		outside_top(int size, int **ysq, int coln, int expected);
int		outside_floor(int size, int **ysq, int coln, int expected);
int		outside_left(int size, int **ysq, int row, int expected);
int		outside_right(int size, int **ysq, int row, int expected);
int		check_errors_input(int size, char *argv, int **input);
void	ini_table(int **table, int n, int m);
int		free_table(int **table, int n);
int		finish_correct_recursion(int *table);
int		get_table_size(char *argv);

void	ini_possible_values(int size, int **ysq, int index, int *possible_val)
{
	int	i;
	int	used_number;

	i = 0;
	while (i < size)
	{
		possible_val[i] = 1;
		++i;
	}
	i = index / size - 1;
	while (i >= 0)
	{
		used_number = ysq[i][index % size];
		possible_val[used_number - 1] = 0;
		--i;
	}
	i = index % size - 1;
	while (i >= 0)
	{
		used_number = ysq[index / size][i];
		possible_val[used_number - 1] = 0;
		--i;
	}
}

void	write_table(int **table, int n, int m)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			c = table[i][j] + '0';
			write(1, &c, 1);
			if (j < m - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			++j;
		}
		++i;
	}
}

int	backtracking(int size, int **ysq, int index, int **input)
{
	int	*possible_values;
	int	i;

	possible_values = (int *) malloc (sizeof(int) * size);
	ini_possible_values(size, ysq, index, possible_values);
	i = 0;
	while (i < size)
	{
		if (possible_values[i])
		{
			ysq[index / size][index % size] = i + 1;
			if (index == size * size - 1)
			{
				return (finish_correct_recursion(possible_values));
			}
			else if (backtracking(size, ysq, index + 1, input))
				return (finish_correct_recursion(possible_values));
		}
		++i;
	}
	return (0);
}

void	main2(char *argv)
{
	int	**input;
	int	**ysq;
	int	size;

	size = get_table_size(argv);
	if (!size)
		write(1, "Error\n", 6);
	else
	{
		input = (int **) malloc (sizeof(int *) * 4);
		ysq = (int **) malloc (sizeof(int *) * size);
		ini_table(input, 4, size);
		ini_table(ysq, size, size);
		if (check_errors_input(size, argv, input))
			write(1, "Error\n", 6);
		else
		{
			if (backtracking(size, ysq, 0, input))
				write_table(ysq, size, size);
			else
				write(1, "Error\n", 6);
		}
		free_table(input, 4);
		free_table(ysq, size);
	}
}
