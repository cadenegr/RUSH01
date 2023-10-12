#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    ft_visible_nums(const char *str);
char    ft_rev_visible_nums(const char *str);
char    *ft_poss(char *str);

// Function to swap two elements in an array
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate all permutations of a sequence and concatenate them to the main string
void generatePermutations(char *sequence, int start, int end, char *arg, char *my_string) {
    static char result[100]; // Assuming a maximum length for the result string

    if (start == end) {
        // If a permutation is found, copy it to the result
         if (ft_visible_nums(sequence) == arg[0])
            if (ft_rev_visible_nums(sequence) == arg[1]){       
                strcpy(result, sequence);
                strcat(my_string, result); // Concatenate it to the main string
            }
    } else {
        for (int i = start; i <= end; i++) {
            swap(&sequence[start], &sequence[i]); // Swap characters
            generatePermutations(sequence, start + 1, end, arg, my_string); // Recursively generate permutations
            swap(&sequence[start], &sequence[i]); // Backtrack (restore the original order)
        }
    }
}

// int main() {
//     char sequence1[] = "1234"; // Change this to your desired sequence
//     char sequence2[] = "ABCD"; // Change this to your second desired sequence
//     int length1 = strlen(sequence1);
//     int length2 = strlen(sequence2);

//     char mainString[1000] = ""; // Initialize an empty main string to store results

//     // Generate permutations for the first sequence and concatenate to mainString
//     generatePermutations(sequence1, 0, length1 - 1, mainString);

//     // Generate permutations for the second sequence and concatenate to mainString
//     generatePermutations(sequence2, 0, length2 - 1, mainString);

//     printf("All permutations are:\n%s\n", mainString);

//     return 0;
// }
