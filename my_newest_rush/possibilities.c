#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		s[0] = '\0';
	}
	if (!s || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			str[i] = s[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(s) + ft_strlen(buffer)] = '\0';
	free(s);
	return (str);
}

char    *ft_poss(char *str)
{
    static char *string = 0;
    // char *string;
    // int i = 0;
    // size_t len;
    // string = 0;
    // len = strlen(string);
    string = strcat(string, str);

    // while (str[i])
    // {
    //     string[len] = str[i];
    //     i++;
    //     len++;
    // }
    printf("%s", string);
    return (string);
}