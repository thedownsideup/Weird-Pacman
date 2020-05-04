#include <stdio.h>
#include <math.h>
#include "func.h"

void DrawPacman(int degree, int radius, char direction){
	int i, j;
  switch (direction) {
	//Pacman facing to the RIGHT
    case 'r':

	switch (degree) {

	case 0:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (i*i + j*j < 0.75*radius*radius)
					printf("# ");
				else
					printf("  ");
			}
			printf("\n");
		}
		break;

	case 90:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (i < 0)
				{
					if (i*i + j*j < 0.75*radius*radius && j < -i)
						printf("# ");
					else
						printf("  ");
				}

				else
				{
					if (i*i + j*j < 0.75*radius*radius && j < i)
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;

	case 120:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (i < 0)
				{
					if (i*i + j*j < 0.75*radius*radius && j < sqrt(3)*(-i) / 3)
						printf("# ");
					else
						printf("  ");
				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && j < sqrt(3)*i / 3)
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;

	case 60:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (i < 0)
				{
					if (i*i + j*j < 0.75*radius*radius && j < sqrt(3)*(-i))
						printf("# ");
					else
						printf("  ");

				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && j < sqrt(3)*i)
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;
	}
	break;
	//Pacman facing to the LEFT
case 'l':

	switch (degree) {

	case 0:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (i*i + j*j < 0.75*radius*radius)
					printf("# ");
				else
					printf("  ");
			}
			printf("\n");
		}
		break;

	case 90:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (i < 0)
				{
					if (i*i + j*j < 0.75*radius*radius && j > i)
						printf("# ");
					else
						printf("  ");

				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && j > -i)
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;

	case 120:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (i < 0)
				{
					if (i*i + j*j < 0.75*radius*radius && j > sqrt(3)*(i) / 3)
						printf("# ");
					else
						printf("  ");

				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && j > sqrt(3)*(-i) / 3)
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;

	case 60:
		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (i < 0)
				{
					if (i*i + j*j < 0.75*radius*radius && j > sqrt(3)*(i))
						printf("# ");
					else
						printf("  ");

				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && j > sqrt(3)*(-i))
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}

		break;
	}
	break;
	//Pacman facing UPward
case 'u':

	switch (degree) {

	case 0:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (i*i + j*j < 0.75*radius*radius)
					printf("# ");
				else
					printf("  ");
			}
			printf("\n");
		}
		break;

	case 90:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (j < 0)
				{
					if (i*i + j*j < 0.75*radius*radius && i > j)
						printf("# ");
					else
						printf("  ");

				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && i > -j)
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;

	case 120:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (j < 0)
				{
					if (i*i + j*j < 0.75*radius*radius && i > sqrt(3)*(j) / 3)
						printf("# ");
					else
						printf("  ");

				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && i > sqrt(3)*(-j) / 3)
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;

	case 60:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (j < 0)
				{
					if (i*i + j*j < 0.75*radius*radius && i > sqrt(3)*(j))
						printf("# ");
					else
						printf("  ");

				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && i > sqrt(3)*(-j))
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;
	}
	break;
	//Pacman facing DOWNward
case 'd':

	switch (degree) {

	case 0:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (i*i + j*j < 0.75*radius*radius)
					printf("# ");
				else
					printf("  ");
			}
			printf("\n");
		}
		break;

	case 90:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (j > 0)
				{
					if (i*i + j*j < 0.75*radius*radius && i < j)
						printf("# ");
					else
						printf("  ");

				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && i < -j)
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;

	case 120:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (j > 0)
				{
					if (i*i + j*j < 0.75*radius*radius && i < sqrt(3)*(j) / 3)
						printf("# ");
					else
						printf("  ");

				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && i < sqrt(3)*(-j) / 3)
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;

	case 60:

		for (i = -radius; i <= radius; i++)
		{
			for (j = -radius; j <= radius; j++)
			{
				if (j > 0)
				{
					if (i*i + j*j < 0.75*radius*radius && i < sqrt(3)*(j))
						printf("# ");
					else
						printf("  ");

				}
				else
				{
					if (i*i + j*j < 0.75*radius*radius && i < sqrt(3)*(-j))
						printf("# ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		break;
	}
	break;
}

	}
