#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str);
int	ft_isdigit(int c);
int	ft_isspace(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int ft_sorting(char *str);

char	*ft_sort_arg(char *dest, char *src)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	// sort_str = ft_calloc(600, 1);
	while (i < len)
	{
		dest[j] = src[i];
		dest[j + 1] = src[i + 8];
		i = i + 2;
		j = j + 2;
		if (i == 8 || i == 24)
			i = i + 8;
	}
	dest[j] = '\0';
	// printf("%s\n\n", dest);
	// ft_sorting(sort_str);
	return (dest);
}

int ft_arg_format(char *str)
{
	int i;
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
	// ft_sort_arg(str);
	return (1);
}

int ft_arg(char * main_arg)
{
	int len;

	len = ft_strlen(main_arg);
	if (len != 31)
		return (0);
	return(ft_arg_format(main_arg));
}