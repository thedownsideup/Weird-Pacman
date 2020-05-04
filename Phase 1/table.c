#include "func.h"
#include <stdio.h>

void table(int a, int cols, int rows)
{
	int i, j;
	for (j = 0; j <= a*rows; j++)
	{
		for (i = 0; i <= a*cols + a + 3; i++)
		{
			if (j% a == 0)
			{
				printf(" -");
			}
			else
			{
				if (i% a == 0) { printf(" | "); }

				else { printf("  "); }
			}

		}
		printf("\n");
	}

}