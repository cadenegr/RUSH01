#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    ft_visible_nums(const char *str);
char    ft_rev_visible_nums(const char *str);
char    *ft_poss(char *str);

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

char    *generatePermutations(char *sequence, int start, int end, char *arg)
{
    // static int count = 0;
    int i;
    if (start == end)
    {
        if (ft_visible_nums(sequence) == arg[0])
            if (ft_rev_visible_nums(sequence) == arg[1])
                ft_poss(sequence);

        // printf("%s\n", sequence);
        // count++;
        // printf("%d\n", count);
    }
    else
    {
        i = start;
        while (i <= end)
        {
            swap(&sequence[start], &sequence[i]);
            generatePermutations(sequence, start + 1, end, arg);
            swap(&sequence[start], &sequence[i]);
            i++;
        }
    }
    // if (count == end)
        return ();
}

// int main()
// {
//     char sequence[] = "1234";
//     int length = strlen(sequence);

//     printf("All permutations of %s are:\n", sequence);
//     generatePermutations(sequence, 0, length - 1);

//     return 0;
// }
