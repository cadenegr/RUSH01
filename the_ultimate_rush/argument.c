/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:55:56 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/13 12:31:40 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*sort_argument(char *dest, char *src)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		dest[j] = src[i];
		dest[j + 1] = src[i + ((len + 1) / 4)];
		i = i + 2;
		j = j + 2;
		if (i == (len + 1) / 4 || i == ((len / 2) + len) / 2)
			i = i + ((len + 1) / 4);
	}
	dest[j] = '\0';
	return (dest);
}

int	argument_format(char *str, int num)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (ft_isdigit(str[i]))
			i = i + 2;
		else
			return (0);
	}
	i = 1;
	while (i < len)
	{
		if (ft_isspace(str[i]) && i != len)
			i = i + 2;
		else
			return (0);
	}
	return (1);
}

int	argument(char *main_arg, int num)
{
	int	len;
	int	argument_length;

	len = ft_strlen(main_arg);
	argument_length = (num * 8) - 1;
	if (len != argument_length)
		return (0);
	return (argument_format(main_arg, num));
}

int	check_argument(char *str, int num)
{
	if (argument(str, num) == 0)
	{
		write(1, "ERROR!_1", 8);
		return (0);
	}
	return (1);
}
