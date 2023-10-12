#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// int	ft_strlen(char *sec_str)
// {
// 	int	i;

// 	i = 0;
// 	if (!sec_str[i])
// 		return (0);
// 	while (sec_str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char *s, char *buffer)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*sec_str;

// 	if (!s)
// 	{
// 		s = (char *)malloc(1 * sizeof(char));
// 		s[0] = '\0';
// 	}
// 	if (!s || !buffer)
// 		return (NULL);
// 	sec_str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(buffer)) + 1));
// 	if (sec_str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (s)
// 		while (s[++i] != '\0')
// 			sec_str[i] = s[i];
// 	while (buffer[j] != '\0')
// 		sec_str[i++] = buffer[j++];
// 	sec_str[ft_strlen(s) + ft_strlen(buffer)] = '\0';
// 	free(s);
// 	return (sec_str);
// }



void generatePermutations(char *sequence, int start, int end, char *arg, char *my_string);
void    extract_rows(char *sec_str, int start, char *line);
char    *extract_cols(char *sec_str, int start, char *line);
void extractAndPrintDigits(const char *line);

int main()
{
    int i = 0;
    int j = 0;
    char argument[] = "2122231421222314";
    char arg[3];
    char sequence[] = "1234";
    char separator = 65;
    char my_string[1000] = "";
    char sec_str[1000] = "";
    char final[100] = "";
    int length = strlen(sequence);
    int len;

    // int result = ft_visible_nums();
    // int result2 = ft_rev_visible_nums();

    // printf("count: %d\n", result2);
    // printf("reversed %d\n", result);

    // printf("All permutations of %s are:\n", sequence);
    while (argument[i])
    {
        if (j < 2)
        {
            arg[j] = argument[i];
            j++;
            i++;
        }
        if (j == 2)
        {
            arg[j] = 0;
            j = 0;
            // printf ("%s\n", arg);
            generatePermutations(sequence, 0, length - 1, arg, my_string);
            len = strlen(my_string);
            while (j < 4)
            {
                my_string[len] = separator;
                len++;
                j++;
            }
            my_string[len] = '\0';
            separator = separator + 1;
            j = 0;
        }
    }
    // printf ("\n%s\n", my_string);
    // sec_str = my_string;
    extract_rows(my_string, 0, sec_str);
    // printf ("\n%s\n", sec_str);
	int start = 0;
    while (my_string[start] != 'D')
		start++;
	start = start + 4;
    extract_cols(my_string, start, sec_str);
    // printf ("\n%s\n", sec_str);
	start = 0;
    while (sec_str[start] != 'D')
		start++;
	start = start + 4;
    extract_rows(sec_str, 0, final);
    extract_cols(sec_str, start, final);
    // printf("\n%s\n", final);
	// printf("%lu", strlen(final));
	extractAndPrintDigits(final);

    // memset(sec_str, 0, sizeof(sec_str));
	// start = 0;
    // while (final[start] != 'D')
	// 	start++;
	// start = start + 4;
    // extract_rows(final, 0, sec_str);
    // extract_cols(final, start, sec_str);
    // printf("\n%s\n", sec_str);


    return 0;
}

// 4231 4312 4132 3214 3124 1432 2431 3421 1243 1342 2341 1423 2143 2413 3241 3142 3412 1234