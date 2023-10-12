#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
int	ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*big_ptr;
	const char	*little_ptr;
	size_t		i;

	big_ptr = big;
	little_ptr = little;
	i = 0;
	if (little_ptr[0] == '\0')
		return ((char *)big_ptr);
	while (big_ptr[i] != '\0' && i < len)
	{
		if (big_ptr[i] == little_ptr[0])
		{
			if (ft_memcmp(&big_ptr[i], little_ptr, ft_strlen(little_ptr)) == 0)
			{
				if (i + ft_strlen(little_ptr) <= len)
					return ((char *)&big_ptr[i]);
			}
		}
		i++;
	}
	return (NULL);
}

char *ft_strncpy(char *dest, const char *src, int start, int n)
{
    char *original_dest = dest;
	int i;

    i = 0;
	while (i < n && src[i + start] != '\0')
	{
        dest[i] = src[i + start];
		i++;
    }
	dest[i] = '\0';
    return original_dest;
}

char	*ft_strnchr(const char *s, int c, int n, size_t start)
{
	int	i;

	i = 0 + start;
	while (s[i] != '\0' && s[i] != (char)c && i <= n)
		i = i + 4;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
#include <stddef.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}