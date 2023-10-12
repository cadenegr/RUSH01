#include <stdio.h>
#include <string.h>
#include <ctype.h>

void extractAndPrintDigits(const char *line)
{
	int	i;
	int	len = strlen(line);

	len = len / 2;
	i = len;
	// printf("%d", len);
	while(line[i])
	{
		if (!isalpha(line[i]))
			printf("%c", line[i]);
		else{
			i = i + 3;
			printf("\n");
		}
		i++;
	}
}
