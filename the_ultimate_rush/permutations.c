/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:03:25 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/13 13:12:51 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	ft_visible_nums(const char *str);
char	ft_rev_visible_nums(const char *str);
char	*ft_poss(char *str);

void	swap(char *x, char *y)
{
	char	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	generator(char *sequence, int start, int end,
	char *arg, char *my_string)
{
	static char	result[100];
	int			i;

	if (start == end)
	{
		if (ft_visible_nums(sequence) == arg[0])
		{
			if (ft_rev_visible_nums(sequence) == arg[1])
			{
				strcpy(result, sequence);
				strcat(my_string, result);
			}
		}
	}
	else
	{
		i = start;
		while (i <= end)
		{
			swap(&sequence[start], &sequence[i]);
			generatePermutations(sequence, start + 1, end, arg, my_string);
			swap(&sequence[start], &sequence[i]);
			i++;
		}
	}
}

