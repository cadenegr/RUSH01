/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:41:28 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/13 12:34:15 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_argument(char *str, int num);
char	*sort_argument(char *dest, char *src);

int	main(int argc, char **argv)
{
	int		argument_check;
	int		puzzle_size;
	char	sequence;
	char	my_string;
	char	swap_string;

	sequence = "1234";
	my_string = malloc(10000);
	swap_string = malloc(10000);

	if (argc != 2)
	{
		write (1, "ERROR!", 6);
		return (0);
	}
	check_argument(argv[1], puzzle_size);
	sort_argument();
}