#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

size_t	ft_strlen(char *str);
char *ft_strncpy(char *dest, const char *src, int start, int n);
int	ft_check_row(char *str, char *substr, int i);
int	ft_check_col(char *str, char *substr, int i);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_results(char *res, int position);
char	*ft_strnchr(const char *s, int c, int n, size_t start);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);

// int	ft_get_pointer_row(char *str, char *ptr)	
// {
// 	const char *row_ptr;
// 	row_ptr = (ft_strnstr(str, ptr, ft_strlen(str)));
// 	int n = ft_strlen(str) - (row_ptr - str);
// 	return (n);
// }

void extract_rows(char *str, int start, char *line) 
{
    static int place;
	static int next = 0;
    int b;
	static char res[200];
    char substr[5];
	// printf("\nChecking\n");

    place = start + 0;

    // if (place >= len)
    //     return (0);
	// printf("\nChecking\n");
    ft_strncpy(substr, str, place, 4);
	int len = ft_strlen(substr);
	// printf("%d\n", len);
    substr[len] = '\0';
	// printf("\nChecking\n");
	if (isalpha(substr[0]))
	{
		strcpy(res, substr);
        strcat(line, res);
		next++;
	}
	// printf("\nChecking\n");
	if (!isalpha(substr[0]))
	{
		// printf("\nCheckingInside\n");
		b = ft_check_row(str, substr, next);
		// printf("\n%d\n", b);
		if( b == 1)
		{
				// printf("\nCheckingInside\n");
			    ft_strcpy(res, substr);
                ft_strcat(line, res);
		}
	}
    if (str[place + 4] == 68)
	{
		ft_strcpy(res, "DDDD");
        ft_strcat(line, res);
	}
    if (str[place + 4] != 68)
	{
		extract_rows(str, place + 4, line);
	}
	else
	{
		// printf("\n%d   %s\n", place, res);
		place = 0;
    	memset(res, 0, sizeof(res));
		next = 0;
	}
}

void extract_cols(char *str, int start, char *line) 
{
    static int place;
	static int next = 0;
    int b;
	static char res[200];
    char substr[5];
	// printf("\nChecking\n");

    place = start + 0;
	// len = strlen(str);
    // if (place >= len)
    //     return (0);
	// printf("\nChecking\n");
    ft_strncpy(substr, str, place, 4);
	// int len = strlen(substr);
    // substr[len] = '\0';
	// printf("\nChecking\n");
	if (isalpha(substr[0]))
	{
		strcpy(res, substr);
        strcat(line, res);
		next++;
	}
	// printf("\nChecking\n");
	if (!isalpha(substr[0]))
	{
		// printf("\nCheckingInside\n");
		b = ft_check_col(str, substr, next);
		// printf("\n%d\n", b);
		if( b == 1)
		{
				// printf("\nCheckingInside\n");
			    ft_strcpy(res, substr);
                ft_strcat(line, res);
		}
	}
    if (str[place + 4] == 72)
	{
		ft_strcpy(res, "HHHH");
        ft_strcat(line, res);
	}
    if (str[place + 4] != 72)
	{
		extract_cols(str, place + 4, line);
	}
	else
	{
		place = 0;
    	memset(res, 0, sizeof(res));
		next = 0;
	}
}
// char *extract_cols(char *str, int start, char *line) 
// {
//     static int place;
//     int len;
// 	static int next = 0;
// 	static char res[200];
//     char substr[5];

//     place = start;
// 	len = strlen(str);
//     if (place >= len)
//         return (0);
//     ft_strncpy(substr, str, place, 4);
//     substr[5] = '\0';
// 	if (isalpha(substr))
// 		next++;
// 	if (!isalpha(substr))
// 		if(ft_check_col(str, substr, next) != 0)
// 		{
// 			    strcpy(res, substr);
//                 strcat(line, res);
// 		}


//     if (str[place + 4] != 72)
// 	{
//     	return (res);
// 		extract_rows(str, place + 4, line);
// 	}
// 	else
// 	{
// 		return (0);
// 	}
// }


// char *extracting(char *str, int start) 
// {
// 	int i = 0;

// 	while (str[i])
// 	{
// 		if (str[i] == 'A')
// 			a = i; 
// 		if (str[i] == 'B')
// 			b = i;
// 		if (str[i] == 'C')
// 			c = i;
// 		if (str[i] == 'D')
// 			d = i;
// 		i++;
// 	}

// 	if (place < a)
//     {
// 		if (ft_check_row(str, substr, 0) == 0)
//             return (0);
//         else
//             return (ft_check_row(str, substr, 0));
//     }
// 	if (place > a && place < b)
//     {
// 		if (ft_check_row(str, substr, 1) == 0)
//             return (0);
//         else
//             return (ft_check_row(str, substr, 1));
//     }
// 	if (place > b && place < c)
//     {
// 		if (ft_check_row(str, substr, 2) == 0)
//             return (0);
//         else
//             return (ft_check_row(str, substr, 2));
//     }
// 	if (place > c && place < d)
//     {
// 		if (ft_check_row(str, substr, 3) == 0)
//             return (0);
//         else
//             return (ft_check_row(str, substr, 3));
//     }

//     if (str[place + 4] < str[d])
//     	extract_rows(str, place + 4);
// 	else
// 		printf("\n\n");
// 	// ft_pointer(count);
// 	return (0);
// }

// char *extract_cols(char *str, int start)
// {
// 	static int place;
// 	// static int count;
// 	// char *ret;
// 	int len;
//     int d;
// 	int e;
// 	int f;
// 	int g;
// 	int i;
//     int h;

// 	place = start;
// 	len = ft_strlen(str);
//     if (start >= len)
//         return (0);
//     char substr[5];
//     ft_strncpy(substr, str, start, 4);
//     substr[4] = '\0';
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == 'D')
// 			d = i; 
// 		if (str[i] == 'E')
// 			e = i; 
// 		if (str[i] == 'F')
// 			f = i;
// 		if (str[i] == 'G')
// 			g = i;
// 		if (str[i] == 'H')
// 			h = i;
// 		i++;
// 	}
// 	// printf("%s\n", substr);
// 	// printf("%d\n", place);

// 	if (place > d && place < e)
//     {
// 		if (ft_check_row(str, substr, 0) == 0)
//             return (0);
//         else
//             return (ft_check_row(str, substr, 0));
//     }
// 	if (place > e && place < f)
//     {
// 		if (ft_check_row(str, substr, 1) == 0)
//             return (0);
//         else
//             return (ft_check_row(str, substr, 1));
//     }
// 	if (place > f && place < g)
//     {
// 		if (ft_check_row(str, substr, 2) == 0)
//             return (0);
//         else
//             return (ft_check_row(str, substr, 2));
//     }
// 	if (place > g && place < h)
//     {
// 		if (ft_check_row(str, substr, 3) == 0)
//             return (0);
//         else
//             return (ft_check_row(str, substr, 3));
//     }
// 	// if (ret)
// 	// {
// 	// 	printf("ret: %s\n", ret);
// 	// 	i = len - (ft_strnchr(ret, 'E', len, 0) - ret);
// 	// 	i = i - 4;
		
// 	// }

//     if (str[place + 4] != '\0')
// 	    extract_cols(str, place + 4);
// 	else
// 		printf("\n\n");
// 	return (0);
// }