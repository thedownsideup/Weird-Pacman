#include "pacman.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>

void main()
{
	initScreen();
	cookie();
	/*code to draw the table*/
	int table[ROWS_PER_TABLE + 1][COLUMN_PER_TABLE + 1][2] =
	{ { { 1,1 },{ 1,0 },{ 1,0 },{ 1,0 },{ 1,1 },{ 1,0 },{ 0,1 } },
	{ { 0,1 },{ 0,0 },{ 0,1 },{ 0,0 },{ 1,0 },{ 0,1 },{ 0,1 } },
	{ { 0,1 },{ 0,0 },{ 1,0 },{ 0,1 },{ 0,0 },{ 0,0 },{ 0,1 } },
	{ { 1,1 },{ 0,1 },{ 0,0 },{ 1,0 },{ 0,1 },{ 0,0 },{ 0,1 } },
	{ { 0,1 },{ 1,0 },{ 0,0 },{ 0,0 },{ 1,0 },{ 0,1 },{ 0,1 } },
	{ { 1,0 },{ 1,0 },{ 1,0 },{ 1,0 },{ 1,0 },{ 1,0 },{ 0,0 } } };

	int j;
	for (j = 0; j < ROWS_PER_TABLE + 1; j++)
	{
		int i;
		for (i = 0; i < COLUMN_PER_TABLE + 1; i++) {

			int x = i*CELL_WIDTH, y = j*CELL_WIDTH / 2;
			/*code for horizental lines*/
			if (table[j][i][0] == 1)
			{
				gotoxy(x, y);
				int k;
				for (k = 0; k <= CELL_WIDTH; k++) {
					printf("-");
				}

			}

			gotoxy(x, y);
			/*code for vertical lines*/
			if (table[j][i][1] == 1) {
				int k;
				y++; /*added so it won't go out of line*/
				gotoxy(x, y);
				for (k = 0; k < CELL_WIDTH / 2; k++) {
					y++;
					printf("|");
					gotoxy(x, y);
				}

			}
		}
	}
	printMovingPacman(table);

}
