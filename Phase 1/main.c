//code for Pacman's game//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "func.h"
int main()
{
	int request, degree, radius;

	char direction;
	//code for finding out the user's request as an initialization of the program:

	printf("what do you wanna draw?\n0 for exiting the program\n1 for drawing Pacman\n2 for drawing the table\n");
	scanf("%d", &request);

	if (request != 1 && request != 2 && request != 0)
		printf("Error! Your number is not valid.");

	if (request == 0)
		return 0;

	if (request == 1)
	{
		//code for getting all the information for drawing pacman as the users wishes and possible errors:
		printf("Enter the radius(4 - 20)\n");
		scanf("%d", &radius);


		if (radius < 4 || radius>20)
		{
			printf("ERROR! Your radius is not in the range.\n"); return 0;
		}

		printf("Enter Pacman's direction (U, D, R, L)\n");
		scanf(" %c", &direction);

		if (direction != 'u' && direction != 'r' && direction != 'd' && direction != 'l')
		{
			printf("ERROR! The direction you chose does not exist in this game.\n"); return 0;
		}

		printf("Enter the mouth degree\t (0, 60, 90, 120)\n");
		scanf("%d", &degree);

		if (degree != 0 && degree != 60 && degree != 90 && degree != 120)
		{
			printf("ERROR! The degree that you asked for does not exist in this game.\n"); return 0;
		}


		//DRAWING PACMAN

		DrawPacman(degree, radius, direction);
	}

	//DRAWING THE TABLE
	if (request == 2)
	{

		int a, cols, rows;

		printf("Enter the length of each cell\n");
		scanf("%d", &a);

		printf("Enter the number of rows\n");
		scanf("%d", &rows);

		printf("Enter the number of columns\n");
		scanf("%d", &cols);

		table(a, cols, rows);

	}
	return 0;
}
