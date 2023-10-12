#include <stdio.h>
#include <string.h>

char    ft_visible_nums(const char *str)
{
    int count = 1;
    int len = strlen(str);
    int i = 0;
    int j = 0;

    while (i < len - 1)
    {
        if (str[i] >= '1' && str[i] <= '9')
        {
            if (str[j] > str[i + 1])
                j = j + 0;
            else
            {
                count++;
				j = i + 1;
            }
        }
        i++;
    }
    // count = count + '0';
    return count;
}

char    ft_rev_visible_nums(const char *str)
{
    int count = 1;
    int len = strlen(str);
    int i = len;
    int j = len;

    while (i > 0)
    {
        if (str[i] >= '1' && str[i] <= '9')
        {
            if (str[j] > str[i - 1])
                j = j + 0;
            else
            {
                count++;
				j = i - 1;
            }
        }
        i--;
    }
    // count = count + '0';
    return count;
}

int main()
{
    const char *number = "4321";

    int result = ft_visible_nums(number);
    int result2 = ft_rev_visible_nums(number);

    printf("count: %d\n", result);
    printf("reversed %d\n", result2);


    return 0;
}
