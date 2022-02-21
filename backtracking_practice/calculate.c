/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:24:20 by klew              #+#    #+#             */
/*   Updated: 2022/01/16 18:24:51 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	calculate(char array[][4], int col, int row)
{
	int	index;
	int	cnt;

	index = 0;
	cnt_left = 1;
	cnt_right = 1;
	while (index < 3)
	{
		if (array[][index] == '4')
			break ;
		else if (array[][index] < array[][index + 1])
			cnt_left++;
		index++;
	}
	while (index < 3)
	{
		if (array[][index] > array[][index + 1])
			cnt_right++;
		index++;
	}
}
