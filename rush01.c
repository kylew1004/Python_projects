/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:32:48 by klew              #+#    #+#             */
/*   Updated: 2022/01/16 18:22:49 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	main2(char *argv);

void	initialize(char *array)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		array[index] = '0';
		index++;
	}
}

void	initialize2(char *str, char *array)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ' ')
		{
			array[j] = str[index - 1];
			j++;
		}
		index++;
	}
}


int	main(int argc, char **argv)
{
	char	array[16];
	char	col_up[4];
	char	col_down[4];
	char	row_left[4];
	char	row_right[4];
	int	i;
	int	j;

	initialize(col_up);
	initialize(col_down);
	initialize(row_left);
	initialize(row_right);
	initialize2(argv[1], array);

	j = 0;
	while (array[j] != '\0')
	{
		i = 0;
		while (i < 4)
		{
			if (j < 4)
				col_up[i] = array[j];
			else if (j >= 4 && j < 8)
				col_down[i] = array[j];
			else if (j >= 8 && j < 12)
				row_left[i] = array[j];
			else if (j >= 12 && j < 16)
				row_right[i] = array[j];
			i++;
			j++;
		}
	}
	if (argc == 2)
		argv++;
		main2(*argv);
	return (0);
}
