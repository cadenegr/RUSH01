/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:35:33 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/13 13:01:43 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	permutations(int sequence, char *arg, char *return_str)
{
	int		i;
	int		length;
	char	arg[3];
	char	separator;

	length = ft_strlen(sequence);
	generatePermutations(sequence, 0, length - 1, arg, return_str);
	length = strlen(return_str);
	if (!ft_isdigit(return_str[length - 1]))
		return (0);
	i = 0;
	while (i++ < 4)
		return_str[length++] = separator;
	return_str[length] = '\0';
	separator = separator + 1;
}

void	check_permutations(char *str, int sequence, char *return_str)
{
	int		i;
	int		j;
	char	arg[3];

	i = 0;
	while (str[i])
	{
		if (j < 2)
			arg[j++] = str[i++];
		if (j == 2)
		{
			arg[j] = '\0';
			j = 0;
			permutations(sequence, arg, return_str);
		}
	}
}
