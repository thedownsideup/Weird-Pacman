#include "pacman.h"
#include <stdio.h>
#include <math.h>

void initScreen()
{
	COORD coord;
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(stdHandle, CONSOLE_FULLSCREEN_MODE, &coord);

}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int waitAndGetDirection(int waitTime, char *direction)
{
	DWORD start_time, check_time;

	start_time = GetTickCount();
	check_time = start_time + waitTime; //GetTickTime returns time in miliseconds
	char ch = 0;
	char hit = 0;

	while (check_time>GetTickCount())
	{
		if (_kbhit())
		{
			hit = 1;
			ch = _getch();
			if (ch == 0)
				ch = _getch();
			break;
		}
	}

	switch (ch)
	{
	case 'w':
		ch = 'u';
		break;
	case 'z':
		ch = 'd';
		break;
	case 'a':
		ch = 'l';
		break;
	case 's':
		ch = 'r';
		break;
	default:
		break;
	}

	if (ch != *direction && (ch == 'u' || ch == 'd' || ch == 'l' || ch == 'r'))
	{
		*direction = ch;
		return 1;
	}
	else
		return 0;

}

void clearCell(int x, int y)
{
	int i, j, r = PACMAN_RADIUS;
	gotoxy(x, y);
	for (j = -r; j <= r; j++) {
		for (i = -r; i <= 2.5*r; i++) { /*2.5 is a coefficient in order to remove all of pacman without it, it'll leave a trace*/
			printf(" "); /*puts spaces instead*/
		}
		gotoxy(x, ++y);
	}
		
}


void setNextLocation(int *x, int *y, char direction, int table[][COLUMN_PER_TABLE + 1][2])
{
	switch (direction)
	{
	case 'r':
		if (table[*y * 2 / CELL_WIDTH][*x / CELL_WIDTH + 1][1] == 0) /*checks if there's a wall, if there is doesn't move*/
			*x += CELL_WIDTH; /*if there's no wall adds to x to move forward*/
		break;
	case 'l':
		if (table[*y * 2 / CELL_WIDTH][*x / CELL_WIDTH][1] == 0) *x -= CELL_WIDTH; /*if there's no wall subtracts 1 from x to move backward*/
		break;
	case 'u':
		if (table[*y * 2 / CELL_WIDTH][*x / CELL_WIDTH][0] == 0) *y -= CELL_WIDTH / 2; /*if there's no wall adds to x to move upward*/
		break;
	case 'd':
		if (table[*y * 2 / CELL_WIDTH + 1][*x / CELL_WIDTH][0] == 0) *y += CELL_WIDTH / 2; /*if there's no wall subtracts 1 from y to move downward*/
		break;
	} /*all 2s are for | being 2 times bigger than -*/

}



void drawPacman(int dx, int dy, int mouthDegree, char direction)
{
	int i, j, r = PACMAN_RADIUS;
	gotoxy(dx, dy);
	switch (direction) {
	case 'r':

		switch (mouthDegree) {

		case 0:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (i*i + j*j < 0.75*r*r) /*0.75 is a coefficient for making a better looking circle*/
						printf("* ");
					else
						printf("  ");
				}
				gotoxy(dx, ++dy);
			}
			break;


		case 90:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (i < 0)
					{
						if (i*i + j*j < 0.75*r*r && j < -i)
							printf("* ");
						else
							printf("  ");
					}

					else
					{
						if (i*i + j*j < 0.75*r*r && j < i)
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 120:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (i < 0)
					{
						if (i*i + j*j < 0.75*r*r && j < sqrt(3)*(-i) / 3)
							printf("* ");
						else
							printf("  ");
					}
					else
					{
						if (i*i + j*j < 0.75*r*r && j < sqrt(3)*i / 3)
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 60:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (i < 0)
					{
						if (i*i + j*j < 0.75*r*r && j < sqrt(3)*(-i))
							printf("* ");
						else
							printf("  ");

					}
					else
					{
						if (i*i + j*j < 0.75*r*r && j < sqrt(3)*i)
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;
		}
		break;

	case 'l':

		switch (mouthDegree) {

		case 0:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (i*i + j*j < 0.75*r*r)
						printf("* ");
					else
						printf("  ");
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 90:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (i < 0)
					{
						if (i*i + j*j < 0.75*r*r && j > i)
							printf("* ");
						else
							printf("  ");

					}
					else
					{
						if (i*i + j*j < 0.75*r*r && j > -i)
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 120:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (i < 0)
					{
						if (i*i + j*j < 0.75*r*r && j > sqrt(3)*(i) / 3)
							printf("* ");
						else
							printf("  ");

					}
					else
					{
						if (i*i + j*j < 0.75*r*r && j > sqrt(3)*(-i) / 3)
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 60:
			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (i < 0)
					{
						if (i*i + j*j < 0.75*r*r && j > sqrt(3)*(i))
							printf("* ");
						else
							printf("  ");

					}
					else
					{
						if (i*i + j*j < 0.75*r*r && j > sqrt(3)*(-i))
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}

			break;
		}
		break;

	case 'u':

		switch (mouthDegree) {

		case 0:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (i*i + j*j < 0.75*r*r)
						printf("* ");
					else
						printf("  ");
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 90:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (j < 0)
					{
						if (i*i + j*j < 0.75*r*r && i > j)
							printf("* ");
						else
							printf("  ");

					}
					else
					{
						if (i*i + j*j < 0.75*r*r && i > -j)
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 120:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (j < 0)
					{
						if (i*i + j*j < 0.75*r*r && i > sqrt(3)*(j) / 3)
							printf("* ");
						else
							printf("  ");

					}
					else
					{
						if (i*i + j*j < 0.75*r*r && i > sqrt(3)*(-j) / 3)
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 60:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (j < 0)
					{
						if (i*i + j*j < 0.75*r*r && i > sqrt(3)*(j))
							printf("* ");
						else
							printf("  ");

					}
					else
					{
						if (i*i + j*j < 0.75*r*r && i > sqrt(3)*(-j))
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;
		}
		break;

	case 'd':

		switch (mouthDegree) {

		case 0:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (i*i + j*j < 0.75*r*r)
						printf("* ");
					else
						printf("  ");
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 90:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (j > 0)
					{
						if (i*i + j*j < 0.75*r*r && i < j)
							printf("* ");
						else
							printf("  ");

					}
					else
					{
						if (i*i + j*j < 0.75*r*r && i < -j)
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 120:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (j > 0)
					{
						if (i*i + j*j < 0.75*r*r && i < sqrt(3)*(j) / 3)
							printf("* ");
						else
							printf("  ");

					}
					else
					{
						if (i*i + j*j < 0.75*r*r && i < sqrt(3)*(-j) / 3)
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;

		case 60:

			for (i = -r; i <= r; i++)
			{
				for (j = -r; j <= r; j++)
				{
					if (j > 0)
					{
						if (i*i + j*j < 0.75*r*r && i < sqrt(3)*(j))
							printf("* ");
						else
							printf("  ");

					}
					else
					{
						if (i*i + j*j < 0.75*r*r && i < sqrt(3)*(-j))
							printf("* ");
						else
							printf("  ");
					}
				}
				gotoxy(dx, ++dy);
			}
			break;
		}
		break;
	}
	gotoxy(dx, ++dy);
}

void cookie()
{
	int i, j;
	for (j = 0; j < ROWS_PER_TABLE; j++)
		for (i = 0; i < COLUMN_PER_TABLE; i++)
		{
			int x = i*CELL_WIDTH + CELL_WIDTH / 2, y = j*CELL_WIDTH / 2 + CELL_WIDTH / 4;
			gotoxy(x, y);
			printf("$");
		}

}
void drawOpeningMouthPacman(int x, int y, char *direction)
{
	drawPacman(x, y, 0, *direction);
	waitAndGetDirection(TIME, direction);
	drawPacman(x, y, 60, *direction);
	waitAndGetDirection(TIME, direction);
	drawPacman(x, y, 90, *direction);
	waitAndGetDirection(TIME, direction);
	drawPacman(x, y, 120, *direction);
	waitAndGetDirection(TIME, direction);
	drawPacman(x, y, 90, *direction);
	waitAndGetDirection(TIME, direction);
	drawPacman(x, y, 60, *direction);
	waitAndGetDirection(TIME, direction);
	drawPacman(x, y, 0, *direction);


}
void printMovingPacman(int table[][COLUMN_PER_TABLE + 1][2])
{
	int x = 1, y = 1, SCORE = 10; /*each cookie has 10 points*/
	char direction = 'r';
	int visit[ROWS_PER_TABLE][COLUMN_PER_TABLE] = { 1 };
	while (1)
	{
		drawOpeningMouthPacman(x, y, &direction);
		clearCell(x, y);

		if (SCORE == ROWS_PER_TABLE*COLUMN_PER_TABLE * 10) break; /*breaks when player wins*/
		waitAndGetDirection(TIME, &direction);
		setNextLocation(&x, &y, direction, table);

		if (visit[y * 2 / CELL_WIDTH][x / CELL_WIDTH] == 0) /*checks if pacman has already been there or not*/
		{
			visit[y * 2 / CELL_WIDTH][x / CELL_WIDTH]++;
			SCORE += 10; /*if pacman hasn't been there, there's still a cookie, eats it and scores!*/
		}
		gotoxy(30, ROWS_PER_TABLE*CELL_WIDTH / 2 + 1);
		printf("SCORE: %d", SCORE);
	}
}

