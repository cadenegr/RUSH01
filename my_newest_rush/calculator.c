#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

size_t	ft_strlen(char *str);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strnchr(const char *s, int c, int n, size_t start);
char	*ft_results(char *res, int position, int index);
void	ft_last_str(char *str);
char    *extract_rows(char *str, int start);
char    *extract_cols(char *str, int start);

void	ft_print_check(const char *result, char *str)
{
    if (result != NULL) 
	    printf("Substring found at position: %ld\n", result - str);
    else
	    printf("Substring not found.\n");
}

int	ft_check_row(char *str, char *substr, int index)
{
    char *first_ptr = "DDDD";
    char *second_ptr = "EEEE";
    char *third_ptr = "FFFF";
    char *fourth_ptr = "GGGG";
	// char *ret;

	const char *first_row = (ft_strnstr(str, first_ptr, ft_strlen(str)));
	const char *second_row = (ft_strnstr(str, second_ptr, ft_strlen(str)));
	const char *third_row = (ft_strnstr(str, third_ptr, ft_strlen(str)));
	const char *fourth_row = (ft_strnstr(str, fourth_ptr, ft_strlen(str)));
	int z = ft_strlen(str) - (first_row - str);
	int y = ft_strlen(str) - (second_row - str);
	int x = ft_strlen(str) - (third_row - str);
	int w = ft_strlen(str) - (fourth_row - str);
	// printf("%d\n", (z - y));
	// printf("%d\n", (y - x));
	// printf("%d\n", (x - w));
	// printf("%d\n", w);
	char *result1 = ft_strnchr(first_row, substr[0], z - y, index);
	char *result2 = ft_strnchr(second_row, substr[1], y - x, index);
	char *result3 = ft_strnchr(third_row, substr[2], x - w, index);
	char *result4 = ft_strnchr(fourth_row, substr[3], w, index);

	if (result1 != NULL && result2 != NULL && result3 != NULL && result4 != NULL)
	{
		// printf("Substring: %s Level:%d\n", substr, index);
		// ft_print_check(result1, str);
		// ft_print_check(result2, str);
		// ft_print_check(result3, str);
		// ft_print_check(result4, str);
		// ft_results(substr, 65, index);
		return (1);

	}
	// printf("%s", ft_results(substr, 68 + index));
	//here i have to send my positive results
	return (0);
}

int	ft_check_col(char *str, char *substr, int index)
{
	// static char	*res;
	char *first_col_ptr = "AAAA";
	char *second_col_ptr = "BBBB";
	char *third_col_ptr = "CCCC";
	char *fourth_col_ptr = "DDDD";
	// char *ret;
	// int	i;

	const char *first_col = (ft_strnstr(str, first_col_ptr, ft_strlen(str)));
	const char *second_col = (ft_strnstr(str, second_col_ptr, ft_strlen(str)));
	const char *third_col = (ft_strnstr(str, third_col_ptr, ft_strlen(str)));
	const char *fourth_col = (ft_strnstr(str, fourth_col_ptr, ft_strlen(str)));
	int a = ft_strlen(str) - (first_col - str);
	int b = ft_strlen(str) - (second_col - str);
	int c = ft_strlen(str) - (third_col - str);
	int d = ft_strlen(str) - (fourth_col - str);
	int A = (ft_strlen(str) - a);
	// printf("%d\n", (a - b));
	// printf("%d\n", (b - c));
	// printf("%d\n", (c - d));
	char *result1 = ft_strnchr(str, substr[0], A, index);
	char *result2 = ft_strnchr(first_col, substr[1], a - b, index);
	char *result3 = ft_strnchr(second_col, substr[2], b - c, index);
	char *result4 = ft_strnchr(third_col, substr[3], c - d, index);

	if (result1 != NULL && result2 != NULL && result3 != NULL && result4 != NULL)
	{
		// printf("Substring: %s Level:%d\n", substr, index);
		// ft_print_check(result1, str);
		// ft_print_check(result2, str);
		// ft_print_check(result3, str);
		// ft_print_check(result4, str);
		// ret = ft_results(substr, 69, index);
		// if (index == 3)
		// 	*ret2 = ret;
		return (1);
	}
	// i = 0;
	// if(*ret2)
	// {
	// 	extract_rows(*ret2, 0);
	// 	while (*ret2[i] != 'D')
	// 	i++;
	// 	i = i - 4;
	// 	extract_cols(ret2, i);
	// }
	return (0);
}